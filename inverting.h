#ifndef INVERTING_H
#define INVERTING_H

#define PI 3.14159265
//typical slew rate value would be assumed to be 0.5 v/us = 500 kHz
#define slew_rate 500000 

class inverting {
public:
//calculates gain for inverting amplifier
float get_gain(float Rf, float Rin); 

//calculates Vout for inverting amplifier
float get_vout(float A, float Vin);

//calculates maximum operating frequency of op amp based on slew rate and peak output voltage
float get_fmax(float Vout);

private:
float A;
float Vout;
float fmax;
};

#endif