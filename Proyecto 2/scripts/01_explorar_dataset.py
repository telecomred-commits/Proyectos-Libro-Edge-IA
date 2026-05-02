import pandas as pd
import matplotlib.pyplot as plt

# ==========================
# 1. Cargar dataset
# ==========================

DATASET_PATH = "../data/raw/samplegas.csv"

df = pd.read_csv(DATASET_PATH)

print("\n=== Primeras filas del dataset ===")
print(df.head())

print("\n=== Información general ===")
print(df.info())

print("\n=== Estadísticas básicas ===")
print(df["mq2_raw"].describe())

# ==========================
# 2. Validar columnas esperadas
# ==========================

required_columns = ["sample_id", "mq2_raw"]

for col in required_columns:
    if col not in df.columns:
        raise ValueError(f"Falta la columna obligatoria: {col}")

# ==========================
# 3. Eliminar datos inválidos
# ==========================

df = df.dropna()
df = df[(df["mq2_raw"] >= 0) & (df["mq2_raw"] <= 4095)]

print("\n=== Dataset después de limpieza básica ===")
print(df.describe())

# ==========================
# 4. Crear etiquetas según rangos definidos
# ==========================

def classify_air_quality(value):
    if value <= 1200:
        return "aire_limpio"
    elif value < 3700:
        return "zona_intermedia"
    else:
        return "alta_concentracion"

df["label"] = df["mq2_raw"].apply(classify_air_quality)

print("\n=== Conteo por clase ===")
print(df["label"].value_counts())

# ==========================
# 5. Guardar dataset etiquetado
# ==========================

OUTPUT_PATH = "dataset_mq2_labeled.csv"
df.to_csv(OUTPUT_PATH, index=False)

print(f"\nDataset etiquetado guardado como: {OUTPUT_PATH}")

# ==========================
# 6. Graficar señal
# ==========================

plt.figure(figsize=(10, 5))
plt.plot(df["sample_id"], df["mq2_raw"])
plt.axhline(y=1200, linestyle="--", label="Límite aire limpio")
plt.axhline(y=3700, linestyle="--", label="Límite alta concentración")
plt.xlabel("sample_id")
plt.ylabel("mq2_raw")
plt.title("Señal analógica MQ-2")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("grafica_mq2_signal.png")
plt.show()

# ==========================
# 7. Histograma
# ==========================

plt.figure(figsize=(8, 5))
plt.hist(df["mq2_raw"], bins=30)
plt.xlabel("mq2_raw")
plt.ylabel("Frecuencia")
plt.title("Distribución de lecturas MQ-2")
plt.grid(True)
plt.tight_layout()
plt.savefig("histograma_mq2.png")
plt.show()