#Importing Libraries
import serial
import json

PORT = 'COM5'
arduinoConsts = {}
arduino = serial.Serial(port=PORT, baudrate=115200, timeout=.1)
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    data = arduino.readline().decode()
    #print((data))
    if x == 'consts':
        try:
            data = json.loads(data)
        except:
            print('erroor in json')
    return data

while write_read('test') == '':
    pass

while True:
    if arduinoConsts == {}:
        arduinoConsts = write_read('consts')
        print(str(arduinoConsts))
        ##print(f"value: {value}",end='\n')