#include "generalfunctions.h"
#include "mainmenu.h"

bool Func::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

// The code for the regex match below was found at: https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit

bool Func::is_numval(std::string num) {
  return std::regex_match(num, std::regex(R"((?:^|\s)([+-]?[[:digit:]]*\.?[[:digit:]]+)(?=$|\s))"));
}

int Func::checkmenuinput(int menu_items){
  int input;
  std::string input_string1;
  bool valid_input1 = false;
  
  do {
    std::cin >> input_string1;
    valid_input1 = is_integer(input_string1);
    if (valid_input1 == false) {
      std::cout << "\nEnter an integer!\n\n";
    } else {
      input = std::stoi(input_string1);
      if (input >= 1 && input <= menu_items) {
        valid_input1 = true;
      } else {
        std::cout << "\nInvalid menu item!\n\n";
        valid_input1 = false;
      }
    }
  } while (valid_input1 == false);
  
  return input;
}

float Func::checkvalinput(){
  float input;
  std::string input_string1;
  bool valid_input1 = false;
  
  do {
    std::cin >> input_string1;
    valid_input1 = is_numval(input_string1);
    if (valid_input1 == false) {
      std::cout << "\nEnter a numerical value!\n\n";
    } else {
      input = std::stof(input_string1);
    }
  } while (valid_input1 == false);
  
  return input;
}

// The code to clear the screen below was found at: https://replit.com/talk/ask/How-to-clear-screen-in-replit-C/10430

void Func::clear() {
  std::cout << "\033[2J\033[1;1H";
}

void Func::go_back_to_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  clear();
  Mainmenu main;
  main.main_menu();
}