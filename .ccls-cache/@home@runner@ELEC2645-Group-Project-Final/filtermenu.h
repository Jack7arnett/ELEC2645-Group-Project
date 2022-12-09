#ifndef FILTER_MENU
#define FILTER_MENU
#include <math.h>
#include <iostream>
#include <regex>
#include 
#define pi 3.14159265
class filtermenu { 
public : 
int menu_items =5;
int input=0;
double resistor=0;
double capacitor=0;
double frequency=0;
double cutoff_frequency=0;
double gain =0;
double inductor=0;
void filter_menu();
void go_back_to_filter();
void sub_main_menu();
int get_user_input();
int get_user_input1();
void select_menu_item(int input);
void select_submenu_item(int input);
void print_filter_menu();
void print_submain_menu();
void go_back_to_main_menu();
bool is_integer(std::string num);
int waituntilvalidnum();
void menu_item_1();
void menu_item_2();
void menu_item_3();
void menu_item_4();
void menu_item_5();
void menu_item_6();
void submenu1_item_1();
void submenu1_item_2();
void submenu2_item_1();
void submenu2_item_2();
void submenu3_item_1();
void submenu3_item_2();
void submenu4_item_1();
void submenu4_item_2();
private: 
};
#endif