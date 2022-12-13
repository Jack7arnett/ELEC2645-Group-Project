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
  void go_back_to_buck();
  void calc_hist();
  std::string input5;
  int I=0; 
  int input=0;
  void storage_check();
  float switch_array[9]={};
  float time_array[9]={};
  float pin_array[9]={};
  float pout_array[9]={};
  float duty_array[9]={};
  float inductor_array[9]={};
  float currip_array[9]={};
  float cap_array[9]={};
  float charge_array[9]={};
  float volrip_array[9]={};
  float Fs=0;
  float Ts=0;
  float Pin=0;
  float Pout=0;
  float K=0;
  float L=0;
  float i=0;
  float Co=0;
  float Q=0;
  float vo=0;
};

#endif