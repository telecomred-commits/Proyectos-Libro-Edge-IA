import joblib
import numpy as np

MODEL_FILE = "modelo_mlp_q1.joblib"
SCALER_FILE = "scaler_mlp_q1.joblib"
OUT_FILE = "mlp_model_esp32.h"

def format_1d(arr):
    return ", ".join(f"{float(x):.8f}f" for x in arr)

def format_2d(arr):
    rows = []
    for row in arr:
        rows.append("  {" + format_1d(row) + "}")
    return ",\n".join(rows)

def main():
    model = joblib.load(MODEL_FILE)
    scaler = joblib.load(SCALER_FILE)

    W1 = np.array(model.coefs_[0], dtype=np.float32)      # (36, 64)
    b1 = np.array(model.intercepts_[0], dtype=np.float32) # (64,)
    W2 = np.array(model.coefs_[1], dtype=np.float32)      # (64, 32)
    b2 = np.array(model.intercepts_[1], dtype=np.float32) # (32,)
    W3 = np.array(model.coefs_[2], dtype=np.float32)      # (32, 3)
    b3 = np.array(model.intercepts_[2], dtype=np.float32) # (3,)

    mean = np.array(scaler.mean_, dtype=np.float32)       # (36,)
    scale = np.array(scaler.scale_, dtype=np.float32)     # (36,)

    with open(OUT_FILE, "w", encoding="utf-8") as f:
        f.write("#pragma once\n\n")
        f.write("// Modelo MLP Q1 exportado desde scikit-learn para ESP32\n\n")

        f.write(f"#define INPUT_SIZE {W1.shape[0]}\n")
        f.write(f"#define H1_SIZE {W1.shape[1]}\n")
        f.write(f"#define H2_SIZE {W2.shape[1]}\n")
        f.write(f"#define OUTPUT_SIZE {W3.shape[1]}\n\n")

        f.write(f"const float scaler_mean[INPUT_SIZE] = {{\n  {format_1d(mean)}\n}};\n\n")
        f.write(f"const float scaler_scale[INPUT_SIZE] = {{\n  {format_1d(scale)}\n}};\n\n")

        f.write(f"const float W1[INPUT_SIZE][H1_SIZE] = {{\n{format_2d(W1)}\n}};\n\n")
        f.write(f"const float b1[H1_SIZE] = {{\n  {format_1d(b1)}\n}};\n\n")

        f.write(f"const float W2[H1_SIZE][H2_SIZE] = {{\n{format_2d(W2)}\n}};\n\n")
        f.write(f"const float b2[H2_SIZE] = {{\n  {format_1d(b2)}\n}};\n\n")

        f.write(f"const float W3[H2_SIZE][OUTPUT_SIZE] = {{\n{format_2d(W3)}\n}};\n\n")
        f.write(f"const float b3[OUTPUT_SIZE] = {{\n  {format_1d(b3)}\n}};\n\n")

    print(f"Archivo generado: {OUT_FILE}")
    print("Dimensiones:")
    print("W1:", W1.shape)
    print("b1:", b1.shape)
    print("W2:", W2.shape)
    print("b2:", b2.shape)
    print("W3:", W3.shape)
    print("b3:", b3.shape)
    print("mean:", mean.shape)
    print("scale:", scale.shape)

if __name__ == "__main__":
    main()