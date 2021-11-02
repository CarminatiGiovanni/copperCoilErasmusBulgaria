# **copperCoilErasmusBulgary**

This is the first program I made with @Dario-Rota during the ERASMUS in LMP industry (Plovdiv, Bulgary).

The goal was to fix some bugs on code written for an arduino board over a machine to wrap copper on a coil.

We also have implemented a serial communication between arduino and a python script.

[Skip](#serial-communication-between-python-and-arduino) here if you want to see the SERIAL section

### **machine description:**

The way the machine wrap the copper on a coil is simple: the coil rotates on itself while a mechanical arm moves the wire from the left to the right and back.

Machine also has a button for starting and a button as a sensor for the position of the arm.

#### **machine components:**

 - **Microstep Driver:** used for the horizontal move of the mechanic arm
 - **Servo Motor IHSV57:** used for the coil rotation
 - **power button (BUTTON):** for starting up the machine
 - **other button (HOME)**: for check the position of the mechanic arm

#### **pins connection:**

the definition of the pins is contained in *PINS.h*:
PIN | type* | I/O | component
--- | ---- | --- | ---------
BUTTON | digital | I | power button
HOME | digital | I | stepper position min
DIRSTEP | digital | O | direction of the stepper (LEFT | RIGHT)
PULSTEP | digital | O | stepper pulseOut pin
ENASERVO | digital | O | servo enable pin
DIRSERVO | digital | O | servo rotation (CLOCKWISE \| COUNTER-CLOCKWISE)
PULSERVO | digital | O | servo pulseOut pin

##### * digital/analog/PWM

## **ARDUINO CODE ANALISYS**

### **file dirs:**

The arduino code inside *'./copperCoil/'* folder is splitted over multiple files:

file | .xxx | code inside
---- | ---- | -----------
copperCoil | .ino | is the main file, contains the Setup and the Loop functions
header | .h | is the main header file that includes all the other headers
PINS | .h | defines the pins connection
GLOBALS | .h | defines the constants variable in the program
functions | .h | contains some functions used in the program
pulseOut | .h | define the pulseOut functions
modifiers | .h | define the functions to modify values such as velocity and coil turns
functions | .cpp | contains the code of the functions defined in *functions.h*
modifiers | .cpp | contains the code of the functions defined in *modifiers.h*
pulseOut | .cpp | contains the code of the functions defined in *pulseOut.h*

more about the functions in the *.h* files.
Every line of code is commented in short in the *.cpp* files for a better understanding.

### **PSEUDOCODE**
#### **setup():**
Setup is the function that arduino call when turns on.

 1. begin the serial communication and set a timeout
 2. calls to pinMode()
 3. starterPosition():
    1. brings back the mechanic arm untill it touches the HOME button (0 pos)
    2. moves the arm to the starter position
    3. rotate the servo

#### **loop():**

 1. check if a serial communication is needed (more in the [SERIAL](#serial-communication-between-python-and-arduino) section)
 2. read the value of the power button, if pressed starts the loop:
 ```
 for n of layers{
    for n of coil_turns{
        rotate the servo
        move the stepper
    }
    invert the direction of the stepper
 }
 starterPosition()
 ```
 3. update last button state
<br><br><br>
-----------------
<br><br>
## SERIAL COMMUNICATION between python and arduino