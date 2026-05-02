import pandas as pd
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree, export_text
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix, ConfusionMatrixDisplay
import joblib

# ==========================
# 1. Cargar dataset etiquetado
# ==========================

DATASET_PATH = "dataset_mq2_labeled.csv"

df = pd.read_csv(DATASET_PATH)

print("\n=== Dataset cargado ===")
print(df.head())

print("\n=== Conteo por clase ===")
print(df["label"].value_counts())

# ==========================
# 2. Preparar variables
# ==========================

X = df[["mq2_raw"]]
y = df["label"]

# ==========================
# 3. Dividir train/test
# ==========================

X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.25,
    random_state=42,
    stratify=y
)

print("\n=== Tamaños de conjuntos ===")
print(f"Train: {len(X_train)} muestras")
print(f"Test:  {len(X_test)} muestras")

# ==========================
# 4. Entrenar árbol de decisión
# ==========================

model = DecisionTreeClassifier(
    max_depth=3,
    random_state=42
)

model.fit(X_train, y_train)

# ==========================
# 5. Evaluar modelo
# ==========================

y_pred = model.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)

print("\n=== Accuracy ===")
print(f"{accuracy:.4f}")

print("\n=== Reporte de clasificación ===")
print(classification_report(y_test, y_pred))

print("\n=== Matriz de confusión ===")
cm = confusion_matrix(y_test, y_pred, labels=model.classes_)
print(cm)

# ==========================
# 6. Mostrar reglas aprendidas
# ==========================

tree_rules = export_text(model, feature_names=["mq2_raw"])

print("\n=== Reglas aprendidas por el árbol ===")
print(tree_rules)

# ==========================
# 7. Guardar modelo entrenado
# ==========================

joblib.dump(model, "modelo_arbol_mq2.joblib")
print("\nModelo guardado como: modelo_arbol_mq2.joblib")

# ==========================
# 8. Guardar gráfica del árbol
# ==========================

plt.figure(figsize=(14, 7))
plot_tree(
    model,
    feature_names=["mq2_raw"],
    class_names=model.classes_,
    filled=True,
    rounded=True
)
plt.title("Árbol de decisión para clasificación de aire con MQ-2")
plt.tight_layout()
plt.savefig("arbol_decision_mq2.png", dpi=300)
plt.show()

# ==========================
# 9. Guardar matriz de confusión
# ==========================

disp = ConfusionMatrixDisplay(
    confusion_matrix=cm,
    display_labels=model.classes_
)

disp.plot()
plt.title("Matriz de confusión - MQ-2")
plt.tight_layout()
plt.savefig("matriz_confusion_mq2.png", dpi=300)
plt.show()