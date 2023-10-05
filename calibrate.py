import serial
import sys
import time
import csv
# Set the serial port name and baud rate
ser = serial.Serial('COM5', 9600) 

try:
    while True:
        ser.reset_input_buffer()
        time.sleep(1)
        user_input = input("Type the ground truth distance (cm) to get a sensor value: ")
        try:
            ground_truth = float(user_input)
        except:
            print("Please enter a distance in cm.")
            pass

        if user_input != '':
            for i in range(30):
                sensor_value = ser.readline().decode().strip()
                with open('sensor_data.csv', mode='a', newline='') as file:
                    writer = csv.writer(file)
                    
                    # Write the data to the CSV file
                    writer.writerow([ground_truth, sensor_value])
                print(f"Distance: {ground_truth} Sensor Reading: {sensor_value}")
        

except KeyboardInterrupt:
    pass

# Close the serial port
ser.close()
