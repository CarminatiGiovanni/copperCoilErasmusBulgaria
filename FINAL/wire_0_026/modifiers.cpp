#include "modifiers.h"

// speed modifier calculator
int calculateTheSpeedModifier(int layer,int turn){
  int speedModifier = 1; // speed modifier = 1 doesn't effect the speed
  if(layer == 0 && turn < LAYER_TURNS/GRADUAL_INDEX) {
    speedModifier = (LAYER_TURNS/GRADUAL_INDEX - turn); //multiplying this number for another index is possible change the increase of the speed
  }
  else if (layer == COIL_LAYERS - 1 && turn > LAYER_TURNS - LAYER_TURNS/GRADUAL_INDEX){
    speedModifier = int(turn - LAYER_TURNS + LAYER_TURNS/GRADUAL_INDEX); // last layer -> deceleration
  }
  else speedModifier = 1; // if is not the first or the last layer
  if(speedModifier == 0) speedModifier = 1; // when the [(LAYER_TURNS - turn) < G_A_I speedModifier || turn < G_A_I] is set to 0, this if statement fix it
  return speedModifier;
}

// turn modifier calculator
int calculateTheLayerTurnsModifier(int layer){
  if(layer % 4 == 0 && layer != 0) return 1; // if is a multiple of 4 but not 0 return 1
  else return 0; //else 0
}
