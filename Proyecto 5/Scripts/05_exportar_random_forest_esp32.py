import joblib
import numpy as np
from pathlib import Path
from sklearn.tree import _tree

# ============================================================
# LABORATORIO 5 - EXPORTACIÓN RANDOM FOREST PARA ESP32
# ============================================================

ROOT = Path(__file__).resolve().parents[1]

MODEL_PATH = ROOT / "data" / "processed" / "modelo_final" / "random_forest_model.pkl"
ENCODER_PATH = ROOT / "data" / "processed" / "modelo_final" / "label_encoder.pkl"

OUTPUT_DIR = ROOT / "ESP32_Model"
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

HEADER_PATH = OUTPUT_DIR / "random_forest_esp32.h"

# ============================================================
# Carga del modelo
# ============================================================

print("============================================")
print("EXPORTACIÓN RANDOM FOREST -> ESP32")
print("============================================")

model = joblib.load(MODEL_PATH)
label_encoder = joblib.load(ENCODER_PATH)

print("\nModelo cargado correctamente.")

# ============================================================
# Configuración
# ============================================================

feature_names = [
    "temp_c",
    "humidity",
    "ldr_pct",
    "mq2_pct"
]

class_names = list(label_encoder.classes_)

# ============================================================
# Función para exportar árbol
# ============================================================

def tree_to_c(tree, feature_names, class_names, tree_index):

    tree_ = tree.tree_

    feature_name = [
        feature_names[i] if i != _tree.TREE_UNDEFINED else "undefined!"
        for i in tree_.feature
    ]

    code = ""

    def recurse(node, depth):

        nonlocal code

        indent = "    " * depth

        if tree_.feature[node] != _tree.TREE_UNDEFINED:

            name = feature_name[node]
            threshold = tree_.threshold[node]

            code += f"{indent}if ({name} <= {threshold:.6f}) {{\n"

            recurse(tree_.children_left[node], depth + 1)

            code += f"{indent}}} else {{\n"

            recurse(tree_.children_right[node], depth + 1)

            code += f"{indent}}}\n"

        else:

            values = tree_.value[node][0]
            class_id = np.argmax(values)
            class_name = class_names[class_id]

            code += f'{indent}return "{class_name}";\n'

    code += f'String tree_{tree_index}(float temp_c, float humidity, float ldr_pct, float mq2_pct) {{\n'

    recurse(0, 1)

    code += "}\n\n"

    return code

# ============================================================
# Construcción del archivo .h
# ============================================================

header = ""

header += "#ifndef RANDOM_FOREST_ESP32_H\n"
header += "#define RANDOM_FOREST_ESP32_H\n\n"

header += "#include <Arduino.h>\n\n"

header += "// ======================================================\n"
header += "// RANDOM FOREST EXPORTADO PARA ESP32\n"
header += "// Laboratorio 5 - Sistema ambiental inteligente\n"
header += "// ======================================================\n\n"

# ============================================================
# Exportar árboles
# ============================================================

n_trees = len(model.estimators_)

print(f"\nNúmero de árboles: {n_trees}")

for idx, estimator in enumerate(model.estimators_):

    print(f"Exportando árbol {idx+1}/{n_trees}")

    tree_code = tree_to_c(
        estimator,
        feature_names,
        class_names,
        idx
    )

    header += tree_code

# ============================================================
# Función de votación final
# ============================================================

header += "String predict_random_forest(float temp_c, float humidity, float ldr_pct, float mq2_pct) {\n\n"

for class_name in class_names:
    header += f"    int votes_{class_name} = 0;\n"

header += "\n"

for idx in range(n_trees):

    header += f"    String pred_{idx} = tree_{idx}(temp_c, humidity, ldr_pct, mq2_pct);\n"

    for class_name in class_names:
        header += f'    if (pred_{idx} == "{class_name}") votes_{class_name}++;\n'

    header += "\n"

header += "    int max_votes = -1;\n"
header += '    String final_prediction = "UNKNOWN";\n\n'

for class_name in class_names:

    header += f"""
    if (votes_{class_name} > max_votes) {{
        max_votes = votes_{class_name};
        final_prediction = "{class_name}";
    }}
"""

header += "\n    return final_prediction;\n"
header += "}\n\n"

header += "#endif\n"

# ============================================================
# Guardado
# ============================================================

with open(HEADER_PATH, "w", encoding="utf-8") as f:
    f.write(header)

print("\n============================================")
print("EXPORTACIÓN FINALIZADA")
print("============================================")
print(f"Archivo generado: {HEADER_PATH}")