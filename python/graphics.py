from tkinter import *

#Data
arduinoConsts = {} #{"SERVO_DELAY": 9, "STEPPER_DELAY": 50, "STEPPER_HORIZONTAL_MOVE": 5, "GRADUAL_INDEX": 64, "DEBOUNCE_DELAY": 30, "COIL_STARTER_POSITION": 1530, "SERVO_ROTATION": 400, "LAYER_TURNS": 436, "COIL_LAYERS": 4}

#Create window
root = Tk()
root.title("Coil Machine Data")
#root.iconbitmap("./images/logo.ico")
root.configure(background='white')
root.geometry("+550+160")


def GetData():
    pass

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

#Show button
show_btn=Button(root,text="Get Data",command=GetData)
show_btn.grid(row=9,column=0,columnspan=2, ipadx=150,ipady=10,padx=10,pady=10)

root.mainloop()
