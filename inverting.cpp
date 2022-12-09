#include "inverting.h"

float inverting::get_gain(float Rf, float Rin) {
  float A = Rf/Rin;
  return A;
}

float inverting::get_vout(float A, float Vin) {
  float Vout = A * Vin ;
  return Vout;
}

float inverting::get_fmax(float Vout) {
  float fmax = slew_rate / (2 * PI * Vout);
  return fmax;
}