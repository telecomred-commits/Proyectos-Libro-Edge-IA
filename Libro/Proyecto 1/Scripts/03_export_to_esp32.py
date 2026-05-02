import json
from pathlib import Path

PARAMS_PATH = Path("models/linear_model_parameters.json")
HEADER_PATH = Path("models/thermal_model.h")

with open(PARAMS_PATH, "r") as f:
    params = json.load(f)

content = f"""#ifndef THERMAL_MODEL_H
#define THERMAL_MODEL_H

const float MODEL_INTERCEPT = {params["intercept"]:.8f};
const float COEF_TEMP_T = {params["coef_temp_t"]:.8f};
const float COEF_HUMIDITY_T = {params["coef_humidity_t"]:.8f};

float predict_temperature(float temp_t, float humidity_t) {{
    return MODEL_INTERCEPT + COEF_TEMP_T * temp_t + COEF_HUMIDITY_T * humidity_t;
}}

#endif
"""

HEADER_PATH.parent.mkdir(parents=True, exist_ok=True)

with open(HEADER_PATH, "w") as f:
    f.write(content)

print("Archivo generado correctamente:")
print(HEADER_PATH)