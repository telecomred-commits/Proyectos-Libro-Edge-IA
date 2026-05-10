import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

# ============================================================
# LABORATORIO 5 - EXPLORACIÓN DEL DATASET
# ============================================================

# -----------------------------
# Rutas
# -----------------------------
ROOT = Path(__file__).resolve().parents[1]

INPUT_PATH = ROOT / "data" / "processed" / "dataset_limpio.csv"

OUTPUT_DIR = ROOT / "data" / "processed" / "graficas"

OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

# -----------------------------
# Carga
# -----------------------------
print("========================================")
print("LABORATORIO 5 - EXPLORACIÓN")
print("========================================")

df = pd.read_csv(INPUT_PATH)

print("\nDimensiones:")
print(df.shape)

print("\nColumnas:")
print(df.columns.tolist())

# ============================================================
# DISTRIBUCIÓN DE CLASES
# ============================================================

plt.figure(figsize=(8, 5))

df["label"].value_counts().plot(kind="bar")

plt.title("Distribución de clases")
plt.xlabel("Clase")
plt.ylabel("Cantidad")

plt.tight_layout()

path_classes = OUTPUT_DIR / "01_distribucion_clases.png"

plt.savefig(path_classes, dpi=300)

print(f"\nGráfica guardada: {path_classes}")

# ============================================================
# HISTOGRAMA TEMPERATURA
# ============================================================

plt.figure(figsize=(8, 5))

plt.hist(df["temp_c"], bins=20)

plt.title("Distribución de temperatura")
plt.xlabel("Temperatura (°C)")
plt.ylabel("Frecuencia")

plt.tight_layout()

path_temp = OUTPUT_DIR / "02_hist_temperatura.png"

plt.savefig(path_temp, dpi=300)

print(f"Gráfica guardada: {path_temp}")

# ============================================================
# HISTOGRAMA LUZ
# ============================================================

plt.figure(figsize=(8, 5))

plt.hist(df["ldr_pct"], bins=20)

plt.title("Distribución de luminosidad")
plt.xlabel("LDR (%)")
plt.ylabel("Frecuencia")

plt.tight_layout()

path_ldr = OUTPUT_DIR / "03_hist_luz.png"

plt.savefig(path_ldr, dpi=300)

print(f"Gráfica guardada: {path_ldr}")

# ============================================================
# HISTOGRAMA MQ2
# ============================================================

plt.figure(figsize=(8, 5))

plt.hist(df["mq2_pct"], bins=20)

plt.title("Distribución MQ-2")
plt.xlabel("MQ2 (%)")
plt.ylabel("Frecuencia")

plt.tight_layout()

path_mq2 = OUTPUT_DIR / "04_hist_mq2.png"

plt.savefig(path_mq2, dpi=300)

print(f"Gráfica guardada: {path_mq2}")

# ============================================================
# MATRIZ DE CORRELACIÓN
# ============================================================

numeric_cols = [
    "temp_c",
    "humidity",
    "ldr_pct",
    "mq2_pct"
]

corr = df[numeric_cols].corr()

print("\nMatriz de correlación:")
print(corr)

plt.figure(figsize=(6, 5))

plt.imshow(corr, interpolation='nearest')

plt.xticks(range(len(numeric_cols)), numeric_cols, rotation=45)
plt.yticks(range(len(numeric_cols)), numeric_cols)

plt.colorbar()

plt.title("Matriz de correlación")

plt.tight_layout()

path_corr = OUTPUT_DIR / "05_correlacion.png"

plt.savefig(path_corr, dpi=300)

print(f"Gráfica guardada: {path_corr}")

# ============================================================
# RESUMEN FINAL
# ============================================================

print("\n========================================")
print("EXPLORACIÓN FINALIZADA")
print("========================================")