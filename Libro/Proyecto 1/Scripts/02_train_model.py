import pandas as pd
import numpy as np
import json
from pathlib import Path
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score
from sklearn.model_selection import train_test_split

DATA_PATH = Path("data/processed/dht22_training.csv")
MODEL_PATH = Path("models/linear_model_parameters.json")

df = pd.read_csv(DATA_PATH)

X = df[["temp_t", "humidity_t"]]
y = df["temp_t_plus_1"]

X_train, X_test, y_train, y_test = train_test_split(
    X, y,
    test_size=0.2,
    shuffle=False
)

model = LinearRegression()
model.fit(X_train, y_train)

y_pred = model.predict(X_test)

mae = mean_absolute_error(y_test, y_pred)
rmse = np.sqrt(mean_squared_error(y_test, y_pred))
r2 = r2_score(y_test, y_pred)

params = {
    "intercept": float(model.intercept_),
    "coef_temp_t": float(model.coef_[0]),
    "coef_humidity_t": float(model.coef_[1]),
    "mae": float(mae),
    "rmse": float(rmse),
    "r2": float(r2)
}

MODEL_PATH.parent.mkdir(parents=True, exist_ok=True)

with open(MODEL_PATH, "w") as f:
    json.dump(params, f, indent=4)

print("\nModelo entrenado correctamente")
print("\nParámetros del modelo:")
print(params)

print("\nEcuación aprendida:")
print(f"T(t+1) = {params['intercept']:.6f} + "
      f"{params['coef_temp_t']:.6f} * temp_t + "
      f"{params['coef_humidity_t']:.6f} * humidity_t")

print("\nMétricas:")
print(f"MAE  = {mae:.4f} °C")
print(f"RMSE = {rmse:.4f} °C")
print(f"R2   = {r2:.4f}")