#ifndef MAIN_MENU
#define MAIN_MENU

#include "stdlib.h"
#include <string>
#include <regex>
#include <iostream>

class Mainmenu {
public:
  void clear();
  void main_menu();
  int get_user_input();
  void print_main_menu();
  void go_back_to_main();
  void menu_item_1();
  void print_con_menu();
  void menu_item_2();
  void menu_item_3();
  void menu_item_4();

private:
  void select_menu_item(int input);
  void select_dc_item(int input);
  bool is_integer(std::string num);
};

#endif