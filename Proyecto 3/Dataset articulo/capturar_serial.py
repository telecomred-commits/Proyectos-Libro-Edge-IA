import serial
import csv
from datetime import datetime

# ===== CONFIGURA ESTO =====
PORT = "COM3"          # cambia si tu ESP sale en otro puerto
BAUD = 115200
OUTFILE = "subj05_sess03_brusco_rep01.csv" # cambia a suave.csv o brusco.csv
TARGET_ROWS = 3000     # filas útiles que quieres guardar

def is_data_line(line: str) -> bool:
    parts = line.split(",")
    if len(parts) != 8:
        return False
    try:
        float(parts[0])  # time
        float(parts[1])  # ax
        float(parts[2])  # ay
        float(parts[3])  # az
        float(parts[4])  # gx
        float(parts[5])  # gy
        float(parts[6])  # gz
        int(float(parts[7]))  # label
        return True
    except ValueError:
        return False

ser = serial.Serial(PORT, BAUD, timeout=1)
print(f"Puerto abierto: {PORT} @ {BAUD}")
print("Presiona RESET en la ESP32 para empezar la captura...")

rows_saved = 0
header_written = False

with open(OUTFILE, "w", newline="", encoding="utf-8") as f:
    writer = csv.writer(f)

    while rows_saved < TARGET_ROWS:
        raw = ser.readline().decode("utf-8", errors="ignore").strip()
        if not raw:
            continue

        # Mostrar todo en pantalla para depurar
        print(raw)

        # Ignorar mensajes de boot y ruido
        if raw.startswith("ets ") or raw.startswith("rst:") or raw.startswith("load:") or raw.startswith("entry "):
            continue

        # Guardar cabecera una sola vez
        if raw == "time,ax,ay,az,gx,gy,gz,label" and not header_written:
            writer.writerow(raw.split(","))
            header_written = True
            print("Cabecera guardada.")
            continue

        # Guardar solo líneas válidas de datos
        if is_data_line(raw):
            writer.writerow(raw.split(","))
            rows_saved += 1

            if rows_saved % 100 == 0:
                print(f"Filas guardadas: {rows_saved}/{TARGET_ROWS}")

ser.close()
print(f"Captura terminada. Archivo guardado: {OUTFILE}")