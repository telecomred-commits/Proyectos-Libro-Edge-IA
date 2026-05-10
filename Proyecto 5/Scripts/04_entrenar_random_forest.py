import pandas as pd
import matplotlib.pyplot as plt
import joblib
from pathlib import Path

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import (
    accuracy_score,
    precision_score,
    recall_score,
    f1_score,
    classification_report,
    confusion_matrix
)

# ============================================================
# LABORATORIO 5 - ENTRENAMIENTO FINAL RANDOM FOREST
# Sistema ambiental inteligente - Edge AI
# ============================================================

ROOT = Path(__file__).resolve().parents[1]

INPUT_PATH = ROOT / "data" / "processed" / "dataset_limpio.csv"

OUTPUT_DIR = ROOT / "data" / "processed" / "modelo_final"
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

MODEL_PATH = OUTPUT_DIR / "random_forest_model.pkl"
ENCODER_PATH = OUTPUT_DIR / "label_encoder.pkl"
REPORT_PATH = OUTPUT_DIR / "reporte_random_forest.txt"
IMPORTANCE_PATH = OUTPUT_DIR / "importancia_variables.csv"
IMPORTANCE_PLOT_PATH = OUTPUT_DIR / "importancia_variables.png"
CM_PLOT_PATH = OUTPUT_DIR / "matriz_confusion_random_forest.png"

print("============================================")
print("LABORATORIO 5 - RANDOM FOREST FINAL")
print("============================================")
print(f"Archivo de entrada: {INPUT_PATH}")

df = pd.read_csv(INPUT_PATH)

print("\n[1] Dimensiones del dataset:")
print(df.shape)

print("\n[2] Distribución de clases:")
print(df["label"].value_counts())

# ============================================================
# Variables de entrada y salida
# ============================================================

feature_cols = [
    "temp_c",
    "humidity",
    "ldr_pct",
    "mq2_pct"
]

target_col = "label"

X = df[feature_cols]
y = df[target_col]

# ============================================================
# Codificación de etiquetas
# ============================================================

label_encoder = LabelEncoder()
y_encoded = label_encoder.fit_transform(y)

print("\n[3] Codificación de clases:")
for idx, class_name in enumerate(label_encoder.classes_):
    print(f"{idx} -> {class_name}")

# ============================================================
# División entrenamiento/prueba
# ============================================================

X_train, X_test, y_train, y_test = train_test_split(
    X,
    y_encoded,
    test_size=0.25,
    random_state=42,
    stratify=y_encoded
)

print("\n[4] Tamaños:")
print(f"X_train: {X_train.shape}")
print(f"X_test : {X_test.shape}")

# ============================================================
# Modelo final Random Forest
# ============================================================

model = RandomForestClassifier(
    n_estimators=100,
    max_depth=8,
    min_samples_split=2,
    min_samples_leaf=1,
    random_state=42
)

print("\n[5] Entrenando Random Forest...")
model.fit(X_train, y_train)

# ============================================================
# Evaluación
# ============================================================

y_pred = model.predict(X_test)

acc = accuracy_score(y_test, y_pred)
prec = precision_score(y_test, y_pred, average="macro", zero_division=0)
rec = recall_score(y_test, y_pred, average="macro", zero_division=0)
f1 = f1_score(y_test, y_pred, average="macro", zero_division=0)

report = classification_report(
    y_test,
    y_pred,
    target_names=label_encoder.classes_,
    zero_division=0
)

cm = confusion_matrix(y_test, y_pred)

print("\n[6] Métricas finales:")
print(f"Accuracy : {acc:.4f}")
print(f"Precision: {prec:.4f}")
print(f"Recall   : {rec:.4f}")
print(f"F1 macro : {f1:.4f}")

print("\nReporte de clasificación:")
print(report)

print("Matriz de confusión:")
print(cm)

# ============================================================
# Guardar modelo y encoder
# ============================================================

joblib.dump(model, MODEL_PATH)
joblib.dump(label_encoder, ENCODER_PATH)

print(f"\n[7] Modelo guardado en: {MODEL_PATH}")
print(f"[8] Encoder guardado en: {ENCODER_PATH}")

# ============================================================
# Importancia de variables
# ============================================================

importance_df = pd.DataFrame({
    "feature": feature_cols,
    "importance": model.feature_importances_
}).sort_values(by="importance", ascending=False)

importance_df.to_csv(IMPORTANCE_PATH, index=False, encoding="utf-8")

print("\n[9] Importancia de variables:")
print(importance_df)

plt.figure(figsize=(8, 5))
plt.bar(importance_df["feature"], importance_df["importance"])
plt.title("Importancia de variables - Random Forest")
plt.xlabel("Variable")
plt.ylabel("Importancia")
plt.tight_layout()
plt.savefig(IMPORTANCE_PLOT_PATH, dpi=300)

print(f"Gráfica de importancia guardada en: {IMPORTANCE_PLOT_PATH}")

# ============================================================
# Matriz de confusión como imagen
# ============================================================

plt.figure(figsize=(7, 6))
plt.imshow(cm, interpolation="nearest")
plt.title("Matriz de confusión - Random Forest")
plt.colorbar()

classes = label_encoder.classes_
plt.xticks(range(len(classes)), classes, rotation=45, ha="right")
plt.yticks(range(len(classes)), classes)

for i in range(cm.shape[0]):
    for j in range(cm.shape[1]):
        plt.text(j, i, cm[i, j], ha="center", va="center")

plt.xlabel("Predicción")
plt.ylabel("Clase real")
plt.tight_layout()
plt.savefig(CM_PLOT_PATH, dpi=300)

print(f"Matriz de confusión guardada en: {CM_PLOT_PATH}")

# ============================================================
# Guardar reporte textual
# ============================================================

with open(REPORT_PATH, "w", encoding="utf-8") as f:
    f.write("LABORATORIO 5 - RANDOM FOREST FINAL\n")
    f.write("Sistema ambiental inteligente - Edge AI\n")
    f.write("============================================\n\n")

    f.write("Variables de entrada:\n")
    for col in feature_cols:
        f.write(f"- {col}\n")

    f.write("\nCodificación de clases:\n")
    for idx, class_name in enumerate(label_encoder.classes_):
        f.write(f"{idx} -> {class_name}\n")

    f.write("\nMétricas:\n")
    f.write(f"Accuracy : {acc:.4f}\n")
    f.write(f"Precision: {prec:.4f}\n")
    f.write(f"Recall   : {rec:.4f}\n")
    f.write(f"F1 macro : {f1:.4f}\n")

    f.write("\nReporte de clasificación:\n")
    f.write(report)

    f.write("\nMatriz de confusión:\n")
    f.write(str(cm))

    f.write("\n\nImportancia de variables:\n")
    f.write(importance_df.to_string(index=False))

print(f"Reporte guardado en: {REPORT_PATH}")

print("\n============================================")
print("ENTRENAMIENTO FINALIZADO")
print("============================================")