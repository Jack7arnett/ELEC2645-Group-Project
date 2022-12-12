#ifndef BUCK_MENU
#define BUCK_MENU

#include "stdlib.h"
#include <iostream>
#include <cmath>

class Buckmenu {
public:
  void buck_converter();
private:
  void print_buck_menu();
  void buck_eq_1();
  void buck_eq_2();
  void buck_eq_3();
  void buck_eq_4();
  void buck_eq_5();
  void buck_eq_6();
  void buck_eq_7();
  void buck_eq_8();
  void buck_eq_9();
  void print_duty_menu();
  void duty_eq_1();
  void duty_eq_2();
  void duty_eq_3();
  void duty_eq_4();
  void print_volt_menu();
  void voltrip_eq_1();
  void voltrip_eq_2();
  void select_buck_item(int input);
  void select_duty_item(int input);
  void select_volt_item(int input);
  bool is_integer(std::string num);
  void capacitor_calc(float K, float Vo, float Fs, float vo, float L, float &Co, float&Q);
};

#endif