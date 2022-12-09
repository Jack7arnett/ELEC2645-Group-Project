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
float Vout;
void select_menu_item(int input);
bool is_integer(std::string num);
int waituntilvalidnum(int menu_items);
void clear();

private:

};

#endif