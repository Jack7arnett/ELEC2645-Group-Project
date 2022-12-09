#include "noninverting.h"

float noninverting::get_gain(float Rf, float Rin) {
  float A = 1+(Rf/Rin);
  return A;
}

float noninverting::get_vout(float A, float Vin) {
  float Vout = A * Vin ;
  return Vout;
}

float noninverting::get_fmax(float Vout) {
  float fmax = slew_rate / (2 * PI * Vout);
  return fmax;
}