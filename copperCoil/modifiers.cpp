#include "modifiers.h"

int calculateTheSpeedModifier(int layer,int turn){
  int speedModifier = 1;
  if(layer == 0){
    speedModifier = int((LAYER_TURNS - turn) / GRADUAL_ACCELERATION_INDEX);
    if(speedModifier == 0) speedModifier = 1;
  } else speedModifier = 1;
  return speedModifier;
}

int calculateTheLayerTurnsModifier(int layer){
  if(layer % 4 == 0 && layer != 0) return 1;
  else return 0;
}
