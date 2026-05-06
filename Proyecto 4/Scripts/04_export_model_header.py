from pathlib import Path
import joblib
import numpy as np

# ============================================================
# PROYECTO 4 - DETECCIÓN DE EVENTOS CON HC-SR04
# Script 04: Exportación del modelo a C/C++ para ESP32
# ============================================================

ROOT = Path(r"C:\Users\cresu\OneDrive\Desktop\FULL\Libro\Proyecto 4")

MODEL_PATH = ROOT / "models" / "logistic_regression_hcsr04.joblib"
HEADER_PATH = ROOT / "ESP32_Model" / "logistic_model_hcsr04.h"

FEATURES = [
    "distance_cm",
    "delta_cm",
    "abs_delta_cm",
    "velocity_cm_s",
    "moving_avg_cm"
]


def format_array(values):
    return ", ".join([f"{v:.10f}f" for v in values])


def main():
    print("============================================")
    print("PROYECTO 4 - EXPORTACIÓN MODELO A HEADER .H")
    print("============================================")
    print("Modelo:", MODEL_PATH)
    print("Existe modelo:", MODEL_PATH.exists())

    if not MODEL_PATH.exists():
        raise FileNotFoundError(f"No se encontró el modelo: {MODEL_PATH}")

    pipeline = joblib.load(MODEL_PATH)

    scaler = pipeline.named_steps["scaler"]
    classifier = pipeline.named_steps["classifier"]

    means = scaler.mean_
    scales = scaler.scale_

    weights = classifier.coef_[0]
    bias = classifier.intercept_[0]

    HEADER_PATH.parent.mkdir(parents=True, exist_ok=True)

    header_content = f"""#ifndef LOGISTIC_MODEL_HCSR04_H
#define LOGISTIC_MODEL_HCSR04_H

#include <math.h>

// ============================================================
// PROYECTO 4 - DETECCIÓN DE EVENTOS CON HC-SR04
// Modelo: Regresión logística exportada desde Python
// ============================================================
//
// Orden de features:
// 0: distance_cm
// 1: delta_cm
// 2: abs_delta_cm
// 3: velocity_cm_s
// 4: moving_avg_cm
//
// Decisión:
// probability >= 0.5 -> Evento
// probability <  0.5 -> No evento
// ============================================================

const int NUM_FEATURES = 5;

const float FEATURE_MEAN[NUM_FEATURES] = {{
  {format_array(means)}
}};

const float FEATURE_SCALE[NUM_FEATURES] = {{
  {format_array(scales)}
}};

const float MODEL_WEIGHTS[NUM_FEATURES] = {{
  {format_array(weights)}
}};

const float MODEL_BIAS = {bias:.10f}f;

float sigmoid(float z) {{
  return 1.0f / (1.0f + expf(-z));
}}

float predictEventProbability(float features[NUM_FEATURES]) {{
  float z = MODEL_BIAS;

  for (int i = 0; i < NUM_FEATURES; i++) {{
    float x_scaled = (features[i] - FEATURE_MEAN[i]) / FEATURE_SCALE[i];
    z += MODEL_WEIGHTS[i] * x_scaled;
  }}

  return sigmoid(z);
}}

int predictEventClass(float features[NUM_FEATURES], float threshold = 0.5f) {{
  float probability = predictEventProbability(features);

  if (probability >= threshold) {{
    return 1;
  }}

  return 0;
}}

#endif
"""

    HEADER_PATH.write_text(header_content, encoding="utf-8")

    print("\nHeader generado correctamente en:")
    print(HEADER_PATH)

    print("\nParámetros exportados:")
    print("Means:", means)
    print("Scales:", scales)
    print("Weights:", weights)
    print("Bias:", bias)


if __name__ == "__main__":
    main()