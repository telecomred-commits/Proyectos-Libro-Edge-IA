#ifndef LOGISTIC_MODEL_HCSR04_H
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

const float FEATURE_MEAN[NUM_FEATURES] = {
  121.0691483516f, 1.3581868132f, 4.5747802198f, 1.0191758242f, 121.6140934066f
};

const float FEATURE_SCALE[NUM_FEATURES] = {
  91.7184687688f, 28.6334091158f, 28.2982009137f, 63.6096931187f, 90.7886455752f
};

const float MODEL_WEIGHTS[NUM_FEATURES] = {
  -4.2241799967f, -0.2673355381f, 2.7529437743f, -0.4038712386f, -2.6084615363f
};

const float MODEL_BIAS = -4.4752323437f;

float sigmoid(float z) {
  return 1.0f / (1.0f + expf(-z));
}

float predictEventProbability(float features[NUM_FEATURES]) {
  float z = MODEL_BIAS;

  for (int i = 0; i < NUM_FEATURES; i++) {
    float x_scaled = (features[i] - FEATURE_MEAN[i]) / FEATURE_SCALE[i];
    z += MODEL_WEIGHTS[i] * x_scaled;
  }

  return sigmoid(z);
}

int predictEventClass(float features[NUM_FEATURES], float threshold = 0.5f) {
  float probability = predictEventProbability(features);

  if (probability >= threshold) {
    return 1;
  }

  return 0;
}

#endif
