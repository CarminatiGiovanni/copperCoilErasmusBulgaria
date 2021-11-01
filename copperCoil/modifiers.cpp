#include "modifiers.h"

// speed modifier calculator
int calculateTheSpeedModifier(int layer,int turn){
  int speedModifier = 1; // speed modifier = 1 doesn't effect the speed
  if(layer == 0){ // the only time an acceleration is needed is on the first layer
    speedModifier = int((LAYER_TURNS - turn) / GRADUAL_ACCELERATION_INDEX); // calculate the speedModifier
    if(speedModifier == 0) speedModifier = 1; // when the (LAYER_TURNS - turn) < G_A_I speedModifier is set to 0, this if statement fix it
  } else speedModifier = 1; // if is not the first layer
  return speedModifier;
}

// turn modifier calculator
int calculateTheLayerTurnsModifier(int layer){
  if(layer % 4 == 0 && layer != 0) return 1; // if is a multiple of 4 but not 0 return 1
  else return 0; //else 0
}
