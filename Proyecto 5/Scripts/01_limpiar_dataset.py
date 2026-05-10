import pandas as pd
from pathlib import Path

# ============================================================
# LABORATORIO 5 - SISTEMA AMBIENTAL INTELIGENTE
# Script 01 - Limpieza inicial del dataset multisensor
# ============================================================

# -----------------------------
# Rutas del proyecto
# -----------------------------
ROOT = Path(__file__).resolve().parents[1]

RAW_PATH = ROOT / "data" / "raw" / "data.csv"
PROCESSED_DIR = ROOT / "data" / "processed"
PROCESSED_PATH = PROCESSED_DIR / "dataset_limpio.csv"

PROCESSED_DIR.mkdir(parents=True, exist_ok=True)

# -----------------------------
# Carga del dataset
# -----------------------------
print("============================================")
print("LABORATORIO 5 - LIMPIEZA DEL DATASET")
print("============================================")
print(f"Archivo de entrada: {RAW_PATH}")

df = pd.read_csv(RAW_PATH)

print("\n[1] Dimensiones iniciales:")
print(df.shape)

print("\n[2] Columnas detectadas:")
print(df.columns.tolist())

# -----------------------------
# Normalización de nombres
# -----------------------------
df.columns = df.columns.str.strip()

# -----------------------------
# Eliminación de duplicados
# -----------------------------
duplicados = df.duplicated().sum()
print(f"\n[3] Filas duplicadas detectadas: {duplicados}")

df = df.drop_duplicates()

# -----------------------------
# Revisión de valores nulos
# -----------------------------
print("\n[4] Valores nulos por columna:")
print(df.isnull().sum())

df = df.dropna()

# -----------------------------
# Conversión de tipos numéricos
# -----------------------------
numeric_cols = [
    "sample_id",
    "time_ms",
    "temp_c",
    "humidity",
    "ldr_raw",
    "ldr_pct",
    "mq2_raw",
    "mq2_pct"
]

for col in numeric_cols:
    df[col] = pd.to_numeric(df[col], errors="coerce")

df = df.dropna()

# -----------------------------
# Limpieza de columnas categóricas
# -----------------------------
categorical_cols = [
    "light_state",
    "gas_state",
    "temp_state",
    "label"
]

for col in categorical_cols:
    df[col] = df[col].astype(str).str.strip().str.upper()

# -----------------------------
# Validación de rangos físicos/simulados
# -----------------------------
df = df[
    (df["temp_c"] >= -40) & (df["temp_c"] <= 80) &
    (df["humidity"] >= 0) & (df["humidity"] <= 100) &
    (df["ldr_raw"] >= 0) & (df["ldr_raw"] <= 4095) &
    (df["mq2_raw"] >= 0) & (df["mq2_raw"] <= 4095) &
    (df["ldr_pct"] >= 0) & (df["ldr_pct"] <= 100) &
    (df["mq2_pct"] >= 0) & (df["mq2_pct"] <= 100)
]

# -----------------------------
# Reinicio de índice
# -----------------------------
df = df.reset_index(drop=True)

# -----------------------------
# Reporte final
# -----------------------------
print("\n[5] Dimensiones finales:")
print(df.shape)

print("\n[6] Distribución de clases:")
print(df["label"].value_counts())

print("\n[7] Resumen estadístico:")
print(df[numeric_cols].describe())

# -----------------------------
# Guardado
# -----------------------------
df.to_csv(PROCESSED_PATH, index=False, encoding="utf-8")

print("\n============================================")
print("LIMPIEZA FINALIZADA")
print(f"Archivo generado: {PROCESSED_PATH}")
print("============================================")