import serial #library for the serial communication between arduino and a computer
import ast #library to parse a json string to python Dictionary object
from tkinter import *

PORT = 'COM5' # port where arduino is connected
BAUDRATE = 115200 # rate for the serial communication
arduinoConsts = {} # Dictionary for the consts arduino is sending
arduino = None

root = Tk()
root.title("Coil Machine Data")
#root.iconbitmap("./images/logo.ico")
root.configure(background='white')
root.geometry("+550+160")

#Show data function
def createValues():
    row = 0
    for key in arduinoConsts:
        d=Label(root,text=arduinoConsts[key] )
        d.grid(row=row, column=1,padx=10,pady=10)
        row += 1

# Labels with wariables names
def createLables ():
    row = 0
    for key in arduinoConsts:
        l = Label(root,text=key)
        l.grid(row=row,column=0,padx=10,pady=10)
        row += 1

def write_read(request): # write on arduino a request and read the answer
    arduino.write(bytes(request, 'utf-8')) # write on arduino the string request (encoding utf-8 -> b'request')
    data = arduino.readline().decode() # read the answer of arduino, decode (b'response' -> utf-8) and save the string in data
    return data

def GetData(arduino: serial.Serial):

    global arduinoConsts

    while write_read('test') == '': # because when the serial communication starts the first messages are confused this just makes call until the response is not null
        pass

    arduinoConsts = write_read('consts') # ask for the consts

    try:
        arduinoConsts = ast.literal_eval(arduinoConsts)
        print(arduinoConsts)
        createLables()
        createValues()
    except:
        err = Label(root,text="error in json load")
        err.grid(row=0,column=0,padx=10,pady=10)
    #print(arduinoConsts) # print on console the constst

try:
    arduino = serial.Serial(port=PORT,baudrate=BAUDRATE,timeout=.1) # connect arduino
    GetData(arduino)
except:
    err = Label(root,text="error in connection to arduino")
    err.grid(row=0,column=0,padx=10,pady=10)

def start():
    if arduinoConsts != None:
        arduino.write(bytes('start','utf-8'))

#Show button
show_btn=Button(root,text="start",command=start)
show_btn.grid(row=9,column=0,columnspan=2, ipadx=150,ipady=10,padx=10,pady=10)

root.mainloop()