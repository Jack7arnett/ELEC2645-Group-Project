#ifndef OPAMP
#define OPAMP

#include <iostream>
#include "inverting.h"
#include "noninverting.h"

class Opamp {
public:
void op_amp_menu();
float option;
float Vin;
float Rin;
float Rf;
int n;
int i=0;
double voltageinput[9]={};    
double voltageresult[9]={};
double gainresult[9]={};
double frequencyresult[9]={};
double resistorin_array[9]={};
double resistorf_array [9]={}; 
void select_menu_item(int input);
bool is_integer(std::string num);
int waituntilvalidnum(int menu_items);
void clear();
void history();
std::string input;
int input2;
void go_back_to_opamp();

private:
float A;
float Vout;
float fmax;

};

#endif