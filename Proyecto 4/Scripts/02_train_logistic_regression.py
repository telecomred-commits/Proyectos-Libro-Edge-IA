from pathlib import Path
import pandas as pd
import joblib

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.pipeline import Pipeline
from sklearn.metrics import (
    accuracy_score,
    confusion_matrix,
    classification_report
)

# ============================================================
# PROYECTO 4 - DETECCIÓN DE EVENTOS CON HC-SR04
# Script 02: Entrenamiento con regresión logística
# ============================================================

ROOT = Path(r"C:\Users\cresu\OneDrive\Desktop\FULL\Libro\Proyecto 4")

DATA_PATH = ROOT / "data" / "processed" / "dataset_hcsr04_corrected.csv"
MODEL_PATH = ROOT / "models" / "logistic_regression_hcsr04.joblib"

FEATURES = [
    "distance_cm",
    "delta_cm",
    "abs_delta_cm",
    "velocity_cm_s",
    "moving_avg_cm"
]

TARGET = "event"


def main():
    print("============================================")
    print("PROYECTO 4 - ENTRENAMIENTO REGRESIÓN LOGÍSTICA")
    print("============================================")
    print("Dataset:", DATA_PATH)
    print("Existe dataset:", DATA_PATH.exists())

    if not DATA_PATH.exists():
        raise FileNotFoundError(f"No se encontró el dataset: {DATA_PATH}")

    df = pd.read_csv(DATA_PATH)

    print("\nFilas cargadas:", len(df))
    print("\nDistribución de clases:")
    print(df[TARGET].value_counts())

    X = df[FEATURES]
    y = df[TARGET].astype(int)

    X_train, X_test, y_train, y_test = train_test_split(
        X,
        y,
        test_size=0.25,
        random_state=42,
        stratify=y
    )

    model = Pipeline([
        ("scaler", StandardScaler()),
        ("classifier", LogisticRegression(max_iter=1000))
    ])

    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)
    y_prob = model.predict_proba(X_test)[:, 1]

    acc = accuracy_score(y_test, y_pred)
    cm = confusion_matrix(y_test, y_pred)

    print("\n============================================")
    print("RESULTADOS DEL MODELO")
    print("============================================")
    print("Accuracy:", round(acc, 4))

    print("\nMatriz de confusión:")
    print(cm)

    print("\nReporte de clasificación:")
    print(classification_report(y_test, y_pred))

    print("\nPrimeras 10 probabilidades estimadas:")
    results = pd.DataFrame({
        "real_event": y_test.values,
        "pred_event": y_pred,
        "prob_event": y_prob
    })

    print(results.head(10))

    MODEL_PATH.parent.mkdir(parents=True, exist_ok=True)
    joblib.dump(model, MODEL_PATH)

    print("\nModelo guardado en:")
    print(MODEL_PATH)


if __name__ == "__main__":
    main()