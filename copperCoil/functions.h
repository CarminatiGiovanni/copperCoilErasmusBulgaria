#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//#include <Arduino.h>
#include "header.h"

    /********** rotateServo *******************************
     * it's a complete rotation of the servo motor.
     * ARGS:
     *  delays -> the delay for each servo pulse  
    ********************************************************/
    void rotateServo(int delays); 

    /******* moveStepper *************************************
     * it's for a horizontal move of the stepper 
     * ARGS: 
     *     dir -> could be HIGH or LOW and is the direction (left | right) of the stepper
     *     delays -> delay of the pulseOut
    *************************************************************/
    void moveStepper(bool dir,int delays);

    /******* starterPosition *********************************
     * it's made to bring the machine to the starter position,
     * it moves back the stepper to the starter position
     * than bring the stepper to the point 0 of the coil (COIL_STARTER_POSITION)
     * rotate the servo
    ***********************************************************/ 
    void starterPosition();

#endif
