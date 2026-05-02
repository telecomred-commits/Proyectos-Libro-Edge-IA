#ifndef THERMAL_MODEL_H
#define THERMAL_MODEL_H

const float MODEL_INTERCEPT = 1.98481650;
const float COEF_TEMP_T = 0.98776380;
const float COEF_HUMIDITY_T = -0.03049567;

float predict_temperature(float temp_t, float humidity_t) {
    return MODEL_INTERCEPT + COEF_TEMP_T * temp_t + COEF_HUMIDITY_T * humidity_t;
}

#endif
