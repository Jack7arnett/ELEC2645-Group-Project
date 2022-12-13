#ifndef BOOST_MENU
#define BOOST_MENU

#include "stdlib.h"
#include <iostream>

class Boostmenu {
public:
  void boost_converter();
private:
  void print_boost_menu();
  void boost_eq_1();
  void boost_eq_2();
  void boost_eq_3();
  void boost_eq_4();
  void boost_eq_5();
  void print_duty_menu();
  void duty_eq_1();
  void duty_eq_2();
  void duty_eq_3();
  void duty_eq_4();
  void boost_eq_6();
  void boost_eq_7();
  void boost_eq_8();
  void print_cap_menu();
  void cap_eq_1();
  void cap_eq_2();
  void capacitor_calc1(float K, float Io, float Fs, float vo, float &Co, float &Q1);
  void cap_eq_3();
  void capacitor_calc2(float Vo, float K, float vo, float R, float Fs, float &Co2, float &Q2);
  void boost_eq_9();
  void print_volt_menu();
  void voltrip_eq_1();
  void voltrip_eq_2();
  void select_boost_item(int input);
  void select_duty_item(int input);
  void select_cap_item(int input);
  void select_volt_item(int input);
  void go_back_to_boost();
  void calc_hist();
  std::string input5;
  int I=0; 
  int input=0;
  void storage_check();
  float switch_array1[9]={};
  float time_array1[9]={};
  float pin_array1[9]={};
  float pout_array1[9]={};
  float duty_array1[9]={};
  float inductor_array1[9]={};
  float currip_array1[9]={};
  float cap_array1[9]={};
  float charge_array1[9]={};
  float volrip_array1[9]={};
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