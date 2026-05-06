from pathlib import Path
import pandas as pd
import joblib
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, classification_report

ROOT = Path(r"C:\Users\cresu\OneDrive\Desktop\FULL\Libro\Proyecto 4")

DATA_PATH = ROOT / "data" / "processed" / "dataset_hcsr04_corrected.csv"
MODEL_PATH = ROOT / "models" / "logistic_regression_hcsr04.joblib"
RESULTS_DIR = ROOT / "results"

FEATURES = [
    "distance_cm",
    "delta_cm",
    "abs_delta_cm",
    "velocity_cm_s",
    "moving_avg_cm"
]

TARGET = "event"


def save_confusion_matrix(y_test, y_pred):
    cm = confusion_matrix(y_test, y_pred)

    plt.figure()
    plt.imshow(cm)
    plt.title("Matriz de confusión - Regresión logística")
    plt.xlabel("Predicción")
    plt.ylabel("Clase real")
    plt.xticks([0, 1], ["No evento", "Evento"])
    plt.yticks([0, 1], ["No evento", "Evento"])

    for i in range(2):
        for j in range(2):
            plt.text(j, i, cm[i, j], ha="center", va="center")

    plt.tight_layout()
    plt.savefig(RESULTS_DIR / "confusion_matrix.png", dpi=300)
    plt.close()


def save_probability_distribution(y_test, y_prob):
    results = pd.DataFrame({
        "real_event": y_test.values,
        "prob_event": y_prob
    })

    plt.figure()
    plt.hist(results[results["real_event"] == 0]["prob_event"], bins=20, alpha=0.7, label="No evento")
    plt.hist(results[results["real_event"] == 1]["prob_event"], bins=20, alpha=0.7, label="Evento")
    plt.axvline(0.5, linestyle="--", label="Umbral 0.5")
    plt.title("Distribución de probabilidad estimada")
    plt.xlabel("Probabilidad estimada de evento")
    plt.ylabel("Frecuencia")
    plt.legend()
    plt.tight_layout()
    plt.savefig(RESULTS_DIR / "probability_distribution.png", dpi=300)
    plt.close()


def save_real_vs_predicted(y_test, y_pred):
    compare = pd.DataFrame({
        "real_event": y_test.values,
        "pred_event": y_pred
    }).reset_index(drop=True)

    plt.figure()
    plt.plot(compare["real_event"].values, marker="o", linestyle="", label="Real")
    plt.plot(compare["pred_event"].values, marker="x", linestyle="", label="Predicción")
    plt.title("Comparación clase real vs clase predicha")
    plt.xlabel("Muestra de prueba")
    plt.ylabel("Clase")
    plt.yticks([0, 1], ["No evento", "Evento"])
    plt.legend()
    plt.tight_layout()
    plt.savefig(RESULTS_DIR / "real_vs_predicted.png", dpi=300)
    plt.close()


def main():
    print("============================================")
    print("PROYECTO 4 - EVALUACIÓN DEL MODELO")
    print("============================================")

    if not DATA_PATH.exists():
        raise FileNotFoundError(f"No se encontró el dataset: {DATA_PATH}")

    if not MODEL_PATH.exists():
        raise FileNotFoundError(f"No se encontró el modelo: {MODEL_PATH}")

    RESULTS_DIR.mkdir(parents=True, exist_ok=True)

    df = pd.read_csv(DATA_PATH)
    model = joblib.load(MODEL_PATH)

    X = df[FEATURES]
    y = df[TARGET].astype(int)

    _, X_test, _, y_test = train_test_split(
        X,
        y,
        test_size=0.25,
        random_state=42,
        stratify=y
    )

    y_pred = model.predict(X_test)
    y_prob = model.predict_proba(X_test)[:, 1]

    print("\nReporte de clasificación:")
    print(classification_report(y_test, y_pred))

    save_confusion_matrix(y_test, y_pred)
    save_probability_distribution(y_test, y_prob)
    save_real_vs_predicted(y_test, y_pred)

    print("\nGráficas guardadas en:")
    print(RESULTS_DIR)
    print("\nArchivos generados:")
    print("confusion_matrix.png")
    print("probability_distribution.png")
    print("real_vs_predicted.png")


if __name__ == "__main__":
    main()