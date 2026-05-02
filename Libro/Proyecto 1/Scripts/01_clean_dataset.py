import pandas as pd
from pathlib import Path

RAW_PATH = Path("data/raw/temperatura.csv")
OUT_PATH = Path("data/processed/dht22_training.csv")

df = pd.read_csv(RAW_PATH)

print("\nDataset original:")
print(df.head())

# Limpieza básica
df = df.dropna()
df = df.drop_duplicates()

# Crear variable objetivo
df["temp_t_plus_1"] = df["temperature_c"].shift(-1)

# Eliminar última fila vacía
df = df.dropna()

# Renombrar columnas
df = df.rename(columns={
    "temperature_c": "temp_t",
    "humidity_percent": "humidity_t"
})

# Reordenar columnas
df = df[
    [
        "sample_id",
        "time_ms",
        "temp_t",
        "humidity_t",
        "temp_t_plus_1"
    ]
]

OUT_PATH.parent.mkdir(parents=True, exist_ok=True)

df.to_csv(OUT_PATH, index=False)

print("\nDataset procesado:")
print(df.head())

print("\nArchivo generado:")
print(OUT_PATH)