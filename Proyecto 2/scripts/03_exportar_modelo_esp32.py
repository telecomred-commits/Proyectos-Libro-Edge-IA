import joblib

# ==========================
# 1. Cargar modelo entrenado
# ==========================

MODEL_PATH = "modelo_arbol_mq2.joblib"
OUTPUT_PATH = "air_tree_model.h"

model = joblib.load(MODEL_PATH)

# ==========================
# 2. Extraer umbrales aprendidos
# ==========================

tree = model.tree_
classes = list(model.classes_)

print("\n=== Clases del modelo ===")
print(classes)

print("\n=== Umbrales aprendidos ===")
for i, threshold in enumerate(tree.threshold):
    if threshold != -2:
        print(f"Nodo {i}: mq2_raw <= {threshold:.2f}")

# ==========================
# 3. Crear archivo .h para ESP32
# ==========================

header_code = f"""
#ifndef AIR_TREE_MODEL_H
#define AIR_TREE_MODEL_H

// ======================================================
// Modelo exportado desde Python
// Proyecto 2 - Clasificacion de aire con MQ-2
// Modelo: Arbol de decision
// ======================================================

String predictAirQuality(int mq2_raw) {{

  if (mq2_raw <= 3700) {{
    if (mq2_raw <= 1194) {{
      return "aire_limpio";
    }} else {{
      return "zona_intermedia";
    }}
  }} else {{
    return "alta_concentracion";
  }}

}}

#endif
"""

with open(OUTPUT_PATH, "w", encoding="utf-8") as file:
    file.write(header_code)

print(f"\nArchivo exportado correctamente: {OUTPUT_PATH}")