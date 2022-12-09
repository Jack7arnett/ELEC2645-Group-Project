#ifndef FUNC
#define FUNC

#include "stdlib.h"
#include <string>
#include <regex>
#include <iostream>
#include "mainmenu.h"

class Func {
public:
  void select_menu_item(int input);
  bool is_integer(std::string num);
  int checkmenuinput(int menu_items);
  int checkvalinput();
  void clear();
  void go_back_to_main();

private:

};

#endif