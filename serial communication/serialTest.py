# import serial

# PORT = 'COM5'

# arduino = serial.Serial(PORT,9600)

# while True:
#     if(arduino.in_waiting > 0):
#         line = arduino.readline().decode()
#         print(line,end='')

# Importing Libraries
import serial
PORT = 'COM5'
arduino = serial.Serial(port=PORT, baudrate=115200, timeout=.1)
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    data = arduino.readline().decode()
    return data
while True:
    num = input("Enter a number: ")
    value = write_read(num)
    print(value)
