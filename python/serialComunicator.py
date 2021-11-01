#Importing Libraries
import serial
import json

PORT = 'COM5'
BAUDRATE = 115200
arduinoConsts = {}
arduino = serial.Serial(port=PORT,baudrate=BAUDRATE,timeout=.1)
def write_read(x):
    #print(x)
    arduino.write(bytes(x, 'utf-8'))
    data = arduino.readline().decode()
    #print('doone')
    if x == 'consts':
        try:
            data = json.loads(data)
        except:
            return write_read('consts') #try again
    return data

while write_read('test') == '':
    pass

while True:
    if arduinoConsts == {}:
        arduinoConsts = write_read('consts')
        print(arduinoConsts)