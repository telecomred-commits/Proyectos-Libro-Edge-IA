import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.pipeline import Pipeline
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, classification_report, confusion_matrix

from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.neural_network import MLPClassifier


# ============================================================
# LABORATORIO 5 - COMPARACIÓN DE MODELOS DE IA
# Sistema ambiental inteligente - Edge AI
# ============================================================

ROOT = Path(__file__).resolve().parents[1]

INPUT_PATH = ROOT / "data" / "processed" / "dataset_limpio.csv"
OUTPUT_DIR = ROOT / "data" / "processed" / "resultados_modelos"
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

RESULTS_CSV = OUTPUT_DIR / "comparacion_modelos.csv"


print("============================================")
print("LABORATORIO 5 - COMPARACIÓN DE MODELOS")
print("============================================")
print(f"Archivo de entrada: {INPUT_PATH}")

df = pd.read_csv(INPUT_PATH)

print("\n[1] Dimensiones del dataset:")
print(df.shape)

print("\n[2] Distribución de clases:")
print(df["label"].value_counts())


# ============================================================
# Selección de variables
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
# Modelos a comparar
# ============================================================

models = {
    "Logistic Regression": Pipeline([
        ("scaler", StandardScaler()),
        ("model", LogisticRegression(max_iter=1000, random_state=42))
    ]),

    "Decision Tree": DecisionTreeClassifier(
        max_depth=6,
        random_state=42
    ),

    "Random Forest": RandomForestClassifier(
        n_estimators=100,
        max_depth=8,
        random_state=42
    ),

    "KNN": Pipeline([
        ("scaler", StandardScaler()),
        ("model", KNeighborsClassifier(n_neighbors=5))
    ]),

    "MLP": Pipeline([
        ("scaler", StandardScaler()),
        ("model", MLPClassifier(
            hidden_layer_sizes=(16, 8),
            activation="relu",
            max_iter=1000,
            random_state=42
        ))
    ])
}


# ============================================================
# Entrenamiento y evaluación
# ============================================================

results = []

best_model_name = None
best_f1 = -1

for name, model in models.items():
    print("\n--------------------------------------------")
    print(f"Entrenando modelo: {name}")
    print("--------------------------------------------")

    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)

    acc = accuracy_score(y_test, y_pred)
    prec = precision_score(y_test, y_pred, average="macro", zero_division=0)
    rec = recall_score(y_test, y_pred, average="macro", zero_division=0)
    f1 = f1_score(y_test, y_pred, average="macro", zero_division=0)

    results.append({
        "modelo": name,
        "accuracy": acc,
        "precision_macro": prec,
        "recall_macro": rec,
        "f1_macro": f1
    })

    print(f"Accuracy : {acc:.4f}")
    print(f"Precision: {prec:.4f}")
    print(f"Recall   : {rec:.4f}")
    print(f"F1-score : {f1:.4f}")

    print("\nReporte de clasificación:")
    print(classification_report(
        y_test,
        y_pred,
        target_names=label_encoder.classes_,
        zero_division=0
    ))

    print("Matriz de confusión:")
    cm = confusion_matrix(y_test, y_pred)
    print(cm)

    if f1 > best_f1:
        best_f1 = f1
        best_model_name = name


# ============================================================
# Guardar resultados
# ============================================================

results_df = pd.DataFrame(results)
results_df = results_df.sort_values(by="f1_macro", ascending=False)

results_df.to_csv(RESULTS_CSV, index=False, encoding="utf-8")

print("\n============================================")
print("RESUMEN COMPARATIVO")
print("============================================")
print(results_df)

print("\nMejor modelo según F1 macro:")
print(f"{best_model_name} con F1 macro = {best_f1:.4f}")

print(f"\nArchivo generado: {RESULTS_CSV}")


# ============================================================
# Gráfica comparativa
# ============================================================

plt.figure(figsize=(9, 5))

plt.bar(results_df["modelo"], results_df["f1_macro"])

plt.title("Comparación de modelos - F1 macro")
plt.xlabel("Modelo")
plt.ylabel("F1 macro")
plt.xticks(rotation=30, ha="right")
plt.ylim(0, 1.05)

plt.tight_layout()

plot_path = OUTPUT_DIR / "comparacion_f1_macro.png"
plt.savefig(plot_path, dpi=300)

print(f"Gráfica generada: {plot_path}")

print("\n============================================")
print("COMPARACIÓN FINALIZADA")
print("============================================")