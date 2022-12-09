#include "mainmenu.h"
#include "buckmenu.h"
#include "boostmenu.h"
#include "generalfunctions.h"
#include "filtermenu.h"
#include "opamp.h"

void Mainmenu::main_menu() {
  print_main_menu();
  Func check;
  int input = check.waituntilvalidnum(4);
  select_menu_item(input);
}

void Mainmenu::print_main_menu() {
  std::cout << "\n----------- Main Menu -----------\n";
  std::cout << "|\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. DC-DC Converters\t\t\t|\n";
  std::cout << "|\t2. menu 2          \t\t\t|\n";
  std::cout << "|\t3. Menu 3 - Multiplication\t|\n";
  std::cout << "|\t4. Exit\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t|\n";
  std::cout << "---------------------------------\n";
  std::cout << "\nPlease enter the corresponding number to select a menu item.\n";
  std::cout << "\nSelect item: ";
}

void Mainmenu::select_menu_item(int input) {
  switch (input) {
    case 1:
      menu_item_1();
      break;
    case 2:
      menu_item_2();
      break;
    case 3:
      menu_item_3();
      break;
    default:
      exit(1);
      break;
  }
}

void Mainmenu::menu_item_1() {
  Func clr;
  clr.clear();
  print_con_menu();
  Func check;
  int yourchoice = check.waituntilvalidnum(2);
switch (yourchoice)
{ Buckmenu startbuck;
  Boostmenu startboost;
case 1: startbuck.buck_converter();break;
case 2: startboost.boost_converter();break;
default: std::cout << "Invalid";break;
  }
  go_back_to_main();
}

void Mainmenu::print_con_menu(){
  std::cout << "\n----- DC-DC Converter Menu ------\n";
  std::cout << "|\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t1. Buck Converter\t\t|\n";
  std::cout << "|\t\t2. Boost Coverter\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t|\n";
  std::cout << "---------------------------------\n";
  std::cout << "\nPlease enter the corresponding number to choose a desired DC-DC converter.\n";
  std::cout << "\nSelect item: ";
}

void Mainmenu::go_back_to_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  Func clr;
  clr.clear();
  main_menu();
}

void Mainmenu::menu_item_2() {
  filtermenu filtermenu;
  filtermenu.filter_menu();
  go_back_to_main();
}

void Mainmenu::menu_item_3() {
  Opamp opampmenu;
  opampmenu.op_amp_menu();
  go_back_to_main();
}