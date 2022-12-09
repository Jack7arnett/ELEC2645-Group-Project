#include"filtermenu.h"

void filtermenu :: filter_menu() {
  print_filter_menu();
  menu_items =5;
  int input = get_user_input();
  select_menu_item(input);
}

int  filtermenu::get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else { // if it is an int, check whether in range
      input = std::stoi(input_string); // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

void filtermenu :: select_menu_item(int input) {
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
  case 4:
    menu_item_4();
    break;
  default:
    exit(1);
    break;
  }
}

void filtermenu :: print_filter_menu() {
  std::cout << "\n----------- Main menu -----------\n";
  std::cout << "|\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Menu 1 - RC high pass\t|\n";
  std::cout << "|\t2. Menu 2 - RC low pass\t\t|\n";
  std::cout << "|\t3. Menu 3 - RL low pass\t\t|\n";
  std::cout << "|\t4. Menu 4 - RLC passband\t|\n";
  std::cout << "|\t5. Exit\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t|\n";
}

void filtermenu::go_back_to_filter() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  filter_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool filtermenu ::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

// Created a function to make the code more readable when checking entered values
int filtermenu ::waituntilvalidnum(){
  int input1;
  std::string input_string1;
  bool valid_input1 = false;
  do {
    std::cin >> input_string1;
    valid_input1 = is_integer(input_string1);
    // if input is not an integer, print an error message
    if (valid_input1 == false) {
      std::cout << "\nEnter an integer!\n\n";
    } else {
      input1 = std::stoi(input_string1); // convert to int
    }
  } while (!(valid_input1));
  
  return input1;
}

//// ---------------menue item one ---------------------------------------
void filtermenu ::menu_item_1() 
  { 
  std::cout << "\n----------- RC high pass menu ------------------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Menu 1 - Calculate the Cut off frequency\t\t\t|\n";
  std::cout << "|\t2. Menu 2 - Claculate the gain \t\t\t\t\t\t|\n";
  std::cout << "|\t3. Exit\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "--------------------------------------------------------\n";
    
 std::cout<<"choose from the menu above";
    menu_items=3;
   input = get_user_input();
    switch (input) {
  case 1:
    submenu1_item_1();
    break;
  case 2:
    submenu1_item_2();
    break;
  default:
    exit(1);
    break;
  }
    }
void filtermenu :: submenu1_item_1 (){
  std::cout<<"Input the resistor value";
   resistor = waituntilvalidnum();
    std::cout<<"Input the capacitor value";
   capacitor = waituntilvalidnum();
  cutoff_frequency = 1/(2*pi*resistor*capacitor);
  std::cout<<"cut off frequency ="<<cutoff_frequency;
  go_back_to_filter();
}
    
void filtermenu :: submenu1_item_2(){
std::cout<<"Input the resistor value";
   resistor = waituntilvalidnum();
    std::cout<<"Input the capacitor value";
   capacitor = waituntilvalidnum();
  std::cout<<"Input the frequency";
   frequency = waituntilvalidnum();
  double subgain1 = 2*pi*frequency*resistor*capacitor;
  double subgain2=pow(subgain1,2);
  gain =  2*pi*frequency*resistor*capacitor/
  pow(1+subgain2,1/2);
  std::cout<<"gain="<<gain;
  go_back_to_filter();
  
}
////// menu item 2 ////////////
void filtermenu :: menu_item_2() {
 std::cout << "\n----------- RC low pass menu -------------------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Menu 1 - Calculate the Cut off frequency\t\t\t|\n";
  std::cout << "|\t2. Menu 2 - Claculate the gain \t\t\t\t\t\t|\n";
  std::cout << "|\t3. Exit\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "--------------------------------------------------------\n";
    
    std::cout<<"choose from the menu above";
    menu_items=3;
   input = get_user_input();

    switch (input) {
  case 1:
    submenu2_item_1();
    break;
  case 2:
    submenu2_item_2();
    break;
  default:
    exit(1);
    break;
  }
    }
void filtermenu :: submenu2_item_1 (){
  std::cout<<"Input the resistor value";
   resistor = waituntilvalidnum();
    std::cout<<"Input the capacitor value";
   capacitor = waituntilvalidnum();
  cutoff_frequency = 1/(2*pi*resistor*capacitor);
  std::cout<<"cut off frequency ="<<cutoff_frequency;
  go_back_to_filter();
}
    
void filtermenu :: submenu2_item_2(){
std::cout<<"Input the resistor value";
   resistor = waituntilvalidnum();
    std::cout<<"Input the capacitor value";
   capacitor = waituntilvalidnum();
  std::cout<<"Input the frequency";
   frequency = waituntilvalidnum();
  double subgain1 = 2*pi*frequency*resistor*capacitor;
  double subgain2=pow(subgain1,2);
  gain =  1/pow(1+subgain2,1/2);
  std::cout<<"gain="<<gain;
  go_back_to_filter();
  
}
////// menu item 3

void filtermenu :: menu_item_3() {
   std::cout << "\n----------- RL low pass menu ----------------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Menu 1 - Calculate the Cut off frequency\t\t\t|\n";
  std::cout << "|\t2. Menu 2 - Claculate the gain \t\t\t\t\t\t|\n";
  std::cout << "|\t3. Exit\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "--------------------------------------------------------\n";
  std::cout<<"choose from the menu above";
    menu_items=3;
   input = get_user_input();
    switch (input) {
  case 1:
    submenu3_item_1();
    break;
  case 2:
    submenu3_item_2();
    break;
  default:
    exit(1);
    break;
  }
    }
void filtermenu :: submenu3_item_1 (){
  std::cout<<"Input the resistor value";
   resistor = waituntilvalidnum();
    std::cout<<"Input the inductor value";
   inductor = waituntilvalidnum();
  cutoff_frequency = resistor/(2*pi*inductor);
  std::cout<<"cut off frequency ="<<cutoff_frequency;
  go_back_to_filter();
}
    
void filtermenu :: submenu3_item_2(){
std::cout<<"Input the resistor value";
   resistor = waituntilvalidnum();
    std::cout<<"Input the capacitor value";
   inductor = waituntilvalidnum();
  std::cout<<"Input the frequency";
   frequency = waituntilvalidnum();
  double subgain1=pow(resistor,2);
  double subgain2 = pow(2*pi*frequency*inductor,2);
  double subgain3 = pow(subgain1+subgain2,1/2);
  gain =resistor/subgain3  ;
  std::cout<<"gain="<<gain;
  go_back_to_filter();
}
//// menu item 4 
void filtermenu :: menu_item_4() {
std::cout << "\n----------- RLC passband menu ----------------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Menu 1 - Calculate the passband center frequency\t|\n";
  std::cout << "|\t2. Menu 2 - Claculate the gain \t\t\t\t\t\t|\n";
  std::cout << "|\t3. Exit\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "--------------------------------------------------------\n";
 std::cout<<"choose from the menu above";
    menu_items=3;
   input = get_user_input();
    switch (input) {
  case 1:
    submenu4_item_1();
    break;
  case 2:
    submenu4_item_2();
    break;
  default:
    exit(1);
    break;
  }
    }
void filtermenu :: submenu4_item_1 (){
  std::cout<<"Input the resistor value";
   resistor = waituntilvalidnum();
    std::cout<<"Input the capacitor value";
   inductor = waituntilvalidnum();
  std::cout<<"Input the inductor value";
   inductor = waituntilvalidnum();
  double subfrequency = pow(capacitor*inductor,1/2);
  
  cutoff_frequency =1/2*pi*subfrequency ;
  std::cout<<"center o passband = "<<cutoff_frequency;
  go_back_to_filter();
}
    
void filtermenu :: submenu4_item_2(){
std::cout<<"Input the resistor value";
   resistor = waituntilvalidnum();
    std::cout<<"Input the capacitor value";
   capacitor = waituntilvalidnum();
  std::cout<<"Input the inductor value";
   inductor = waituntilvalidnum();
  std::cout<<"Input the frequency";
   frequency = waituntilvalidnum();
  double subgain1=2*pi*frequency*inductor;
  double subgain2 = 1/(2*pi*frequency*capacitor);
  gain =resistor/(resistor*subgain1*subgain2);
  std::cout<<"gain="<<gain;
  go_back_to_filter();
}