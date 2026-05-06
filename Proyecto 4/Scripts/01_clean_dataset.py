from pathlib import Path
import pandas as pd

# ============================================================
# PROYECTO 4 - DETECCIÓN DE EVENTOS CON HC-SR04
# Script 01: Limpieza y balanceo del dataset
# ============================================================

ROOT = Path(r"C:\Users\cresu\OneDrive\Desktop\FULL\Libro\Proyecto 4")

RAW_PATH = ROOT / "data" / "raw" / "dataset.csv"
PROCESSED_PATH = ROOT / "data" / "processed" / "dataset_hcsr04_corrected.csv"

MAX_REPEATED_SAMPLES = 5
TARGET_RATIO_NO_EVENT = 2  # 2 no-eventos por cada evento


def reduce_repeated_distances(df, max_repeated=5):
    corrected_rows = []

    last_distance = None
    repeated_count = 0

    for _, row in df.iterrows():
        current_distance = row["distance_cm"]

        if current_distance == last_distance:
            repeated_count += 1
        else:
            repeated_count = 1
            last_distance = current_distance

        if repeated_count <= max_repeated:
            corrected_rows.append(row)

    return pd.DataFrame(corrected_rows)


def main():
    print("============================================")
    print("PROYECTO 4 - LIMPIEZA DATASET HC-SR04")
    print("============================================")
    print("Archivo de entrada:", RAW_PATH)
    print("Existe archivo:", RAW_PATH.exists())

    if not RAW_PATH.exists():
        raise FileNotFoundError(f"No se encontró el archivo: {RAW_PATH}")

    df = pd.read_csv(RAW_PATH)

    expected_columns = [
        "sample_id",
        "time_ms",
        "distance_cm",
        "delta_cm",
        "abs_delta_cm",
        "velocity_cm_s",
        "moving_avg_cm",
        "event",
    ]

    missing_columns = [col for col in expected_columns if col not in df.columns]
    if missing_columns:
        raise ValueError(f"Faltan columnas en el dataset: {missing_columns}")

    original_rows = len(df)

    # Limpieza básica
    df = df.dropna()
    df = df[df["distance_cm"] > 0]
    df = df[df["distance_cm"] <= 400]
    df = df[df["event"].isin([0, 1])]
    df["event"] = df["event"].astype(int)

    # Reducir tramos congelados
    df = reduce_repeated_distances(df, MAX_REPEATED_SAMPLES)
    df["event"] = df["event"].astype(int)

    rows_after_cleaning = len(df)

    # Balanceo por submuestreo de la clase mayoritaria
    df_event = df[df["event"] == 1]
    df_no_event = df[df["event"] == 0]

    if len(df_event) == 0:
        raise ValueError("No hay eventos en el dataset. No se puede balancear.")

    n_no_event_target = min(
        len(df_no_event),
        len(df_event) * TARGET_RATIO_NO_EVENT
    )

    df_no_event_balanced = df_no_event.sample(
        n=n_no_event_target,
        random_state=42
    )

    df_balanced = pd.concat([df_no_event_balanced, df_event], axis=0)
    df_balanced = df_balanced.sample(frac=1, random_state=42).reset_index(drop=True)

    PROCESSED_PATH.parent.mkdir(parents=True, exist_ok=True)
    df_balanced.to_csv(PROCESSED_PATH, index=False)

    print("\n============================================")
    print("LIMPIEZA Y BALANCEO FINALIZADOS")
    print("============================================")
    print("Filas originales:", original_rows)
    print("Filas después de limpieza:", rows_after_cleaning)
    print("Filas finales balanceadas:", len(df_balanced))

    print("\nDistribución final de clases:")
    print(df_balanced["event"].value_counts())

    print("\nPorcentaje final de clases:")
    print(df_balanced["event"].value_counts(normalize=True) * 100)

    print("\nArchivo guardado en:")
    print(PROCESSED_PATH)


if __name__ == "__main__":
    main()
