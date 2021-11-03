from tkinter import *

#Data
arduinoConsts = {"SERVO_DELAY": 9, "STEPPER_DELAY": 50, "STEPPER_HORIZONTAL_MOVE": 5, "GRADUAL_INDEX": 64, "DEBOUNCE_DELAY": 30, "COIL_STARTER_POSITION": 1530, "SERVO_ROTATION": 400, "LAYER_TURNS": 436, "COIL_LAYERS": 4}

#Create window
root = Tk()
root.title("Coil Machine Data")
root.iconbitmap("./Images/coil_4583.ico")
root.configure(background='white')
root.geometry("+550+160")

#Show data function
def show():
    #Data
    servo_del_data=Label(root,text=arduinoConsts["SERVO_DELAY"] )
    servo_del_data.grid(row=0, column=1,padx=10,pady=10)

    step_del_data=Label(root,text=arduinoConsts["STEPPER_DELAY"])
    step_del_data.grid(row=1, column=1,padx=10,pady=10)

    step_hor_move_data=Label(root,text=arduinoConsts["STEPPER_HORIZONTAL_MOVE"])
    step_hor_move_data.grid(row=2, column=1,padx=10,pady=10)

    grad_index_data=Label(root,text=arduinoConsts["GRADUAL_INDEX"])
    grad_index_data.grid(row=3, column=1,padx=10,pady=10)

    deb_del_data=Label(root,text=arduinoConsts["DEBOUNCE_DELAY"])
    deb_del_data.grid(row=4, column=1,padx=10,pady=10)

    coil_start_pos_data=Label(root,text=arduinoConsts["COIL_STARTER_POSITION"])
    coil_start_pos_data.grid(row=5, column=1,padx=10,pady=10)

    servo_rot_data=Label(root,text=arduinoConsts["SERVO_ROTATION"])
    servo_rot_data.grid(row=6, column=1,padx=10,pady=10)

    layer_turns_data=Label(root,text=arduinoConsts["LAYER_TURNS"])
    layer_turns_data.grid(row=7, column=1,padx=10,pady=10)

    coil_layers_data=Label(root,text=arduinoConsts["COIL_LAYERS"])
    coil_layers_data.grid(row=8, column=1,padx=10,pady=10)



#Lables
servo_del=Label(root,text="SERVO_DELAY")
servo_del.grid(row=0, column=0,padx=10,pady=10)

step_del=Label(root,text="STEPPER_DELAY")
step_del.grid(row=1, column=0,padx=10,pady=10)

step_hor_move=Label(root,text="STEPPER_HORIZONTAL_MOVE")
step_hor_move.grid(row=2, column=0,padx=10,pady=10)

grad_index=Label(root,text="GRADUAL_INDEX")
grad_index.grid(row=3, column=0,padx=10,pady=10)

deb_del=Label(root,text="DEBOUNCE_DELAY")
deb_del.grid(row=4, column=0,padx=10,pady=10)

coil_start_pos=Label(root,text="COIL_STARTER_POSITION")
coil_start_pos.grid(row=5, column=0,padx=10,pady=10)

servo_rot=Label(root,text="SERVO_ROTATION")
servo_rot.grid(row=6, column=0,padx=10,pady=10)

layer_turns=Label(root,text="LAYER_TURNS")
layer_turns.grid(row=7, column=0,padx=10,pady=10)

coil_layers=Label(root,text="COIL_LAYERS")
coil_layers.grid(row=8, column=0,padx=10,pady=10)


#Show button
show_btn=Button(root,text="Show Data",command=show)
show_btn.grid(row=9,column=0,columnspan=2, ipadx=150,ipady=10,padx=10,pady=10)





root.mainloop()
