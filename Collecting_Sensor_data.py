import serial
import csv
import time

# Set the correct port and baud rate
ser = serial.Serial('COM12', 9600)  # Replace COM3 with your Arduino port
filename = "max30102_data9.csv"

print("Logging started... Press Ctrl+C to stop.")

with open(filename, 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(["IR", "Red"])  # CSV header

    try:
        while True:
            line = ser.readline().decode().strip()
            values = line.split(',')
            if len(values) == 2:
                writer.writerow(values)
                print(values)
            time.sleep(1)
    except KeyboardInterrupt:
        print("Logging stopped.")
        ser.close()
