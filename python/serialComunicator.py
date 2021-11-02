import serial #library for the serial communication between arduino and a computer
import json #library to parse a json string to python Dictionary object

PORT = 'COM5' # port where arduino is connected
BAUDRATE = 115200 # rate for the serial communication
arduinoConsts = {} # Dictionary for the consts arduino is sending
arduino = serial.Serial(port=PORT,baudrate=BAUDRATE,timeout=.1) # connect arduino

def write_read(request): # write on arduino a request and read the answer
    arduino.write(bytes(request, 'utf-8')) # write on arduino the string request (encoding utf-8 -> b'request')
    data = arduino.readline().decode() # read the answer of arduino, decode (b'response' -> utf-8) and save the string in data
    if request == 'consts': # if the request was 'consts' -> parse the string to Dictionary
        try: # because json.loads() can throw an error is use the try-except error handling
            data = json.loads(data) # data is parsed in a dictionary and returned
        except: # the code executed if it's impossible to parse the string
            return write_read('consts') #try again
    return data

while write_read('test') == '': # because when the serial communication starts the first messages are confused this just makes call until the response is not null
    pass

while True: # infinite loop, to stop the program kill the process or use ctrl + c in terminal
    if arduinoConsts == {}: # if no consts are loaded
        arduinoConsts = write_read('consts') # ask for the consts
        print(arduinoConsts) # print on console the consts