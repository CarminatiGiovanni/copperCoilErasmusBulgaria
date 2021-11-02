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

arduino provides a connection with the serial port to communicate with a computer,
that permits to the computer get the constants and the values from the arduino board writing requests as byte strings on the port and waiting for a response printed in the serial by arduino.

The python library that creates this communication is *[pyserial](https://pypi.org/project/pyserial/)*; it's free and to install it is just needed *PIP* installed. For the installation just type *pip install pyserial* in the terminal.

The program we created is used to ask to arduino about the constants contained in *GLOBALS.h*, arduino will send on the serial the globals as a *JSON* object that python will parse in a *Dictionary* structure.


### **pseudocode:**

 1. import pyserial and json libraries
 2. define variables (port baudrate and the *empty Dictionary*)
 3. define ARDUINO CONNECTION
 4. define *write_read(request)* function that send a request to the serial and returns the answer
 5. wait for arduino response on the port with random requests
 6. starts infinite loop:
    1. if consts of arduino are not already taken, call *write_read('consts')* and print them out on console

### __about *write_read(request)*__

this functions makes requests to the arduino board, 'till now arduino only response with json string of consts only when the request is *'consts'*, else just return an error string

arduino only comunicate with *bytes* strings, so is needed a casting from *utf-8 -> bytes* for sending the request. The response is decoded using the attribute *.decode()*

As I said if the request is *'consts'* a response as JSON string is expected, with *json.loads()* function the string is parsed to a dictioary, else is thrown an error and the function recalled again
 