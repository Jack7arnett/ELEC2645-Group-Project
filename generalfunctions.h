#ifndef FUNC
#define FUNC

#include "stdlib.h"
#include <string>
#include <regex>
#include <iostream>

class Func {
public:
  void select_menu_item(int input);
  bool is_integer(std::string num);
  int waituntilvalidnum(int menu_items);
  void clear();

private:

};

#endif