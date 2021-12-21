#ifndef MODIFIERS_H
#define MODIFIERS_H
//#include <Arduino.h>
#include "header.h"


/************* calculateTheSpeedModifier ***********************
 * speed mofifier is the value that gradually increase or decrease the speed of the servo motor
 * ARGS:
 *  layer -> only when on the first layer the acceleration is needed
 *  turn -> index needed for the gradual acceleration
 **************************************************/
int calculateTheSpeedModifier(int layer,int turn);

/** calculateTheLayerTurnsModifier **********************
 * every 4 layers is needed a turn more.
 * **********************************************/
int calculateTheLayerTurnsModifier(int layer);

#endif
