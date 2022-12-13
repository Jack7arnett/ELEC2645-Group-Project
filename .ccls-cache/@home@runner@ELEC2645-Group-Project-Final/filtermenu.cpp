#include"filtermenu.h"

/////////////////
void filtermenu::storage_check(){
do {
  std::cout<<"\nDo you want to store the values of this calculations? ";
    std::cout << "\nEnter 'y' for yes or 'n' for no : ";
    std::cin >> input5;
  } while (input5 != "y" && input5 != "n");
  if (input5 == "y") {
    gainresult[i]= gain;
    frequencyresult[i]= cutoff_frequency;
    resistor_array[i]= resistor;
    capacitor_array [i]= capacitor; 
    inductor_array[i]= inductor;
    frequency_array[i]= frequency;
      resistor=0;
 capacitor=0;
 frequency=0;
 cutoff_frequency=0;
 gain =0;
 inductor=0;
    i=i+1;
    if(i>10){i=0;}
    go_back_to_filter();
  }
  else{
   go_back_to_filter();
  }
  }
////////////////////

void filtermenu :: filter_menu() {
  Func clr;
  clr.clear();
  print_filter_menu();
  menu_items =6;
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
    case 5:
    menu_item_5();
    case 6: 
    Func func;
      func.clear();
      Mainmenu main;
     main.main_menu();
  default:
    exit(1);
    break;
  }
}

void filtermenu :: print_filter_menu() {
  std::cout << "\n----------- Filter menu -----------\n";
  std::cout << "|\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Menu 1 - RC high pass\t|\n";
  std::cout << "|\t2. Menu 2 - RC low pass\t\t|\n";
  std::cout << "|\t3. Menu 3 - RL low pass\t\t|\n";
  std::cout << "|\t4. Menu 4 - RLC passband\t|\n";
  std::cout << "|\t5. history\t\t\t\t\t|\n";
  std::cout << "|\t6. go back to main menu\t\t|\n";
  std::cout << "|\t7. Exit\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t|\n";
   std::cout << "------------------------------------\n";
}

void filtermenu::go_back_to_filter() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to filter menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  Func func;
  func.clear();
  filter_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool filtermenu ::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}
bool filtermenu::is_integer2(std::string num) {
  return std::regex_match(num, std::regex(R"((?:^|\s)([+-]?[[:digit:]]*\.?[[:digit:]]+)(?=$|\s))"));
}
float filtermenu::waituntilvalidnum2(){
  float input;
  std::string input_string1;
  bool valid_input1 = false;
  
  do {
    std::cin >> input_string1;
    valid_input1 = is_integer2(input_string1);
    if (valid_input1 == false) {
      std::cout << "\nEnter a numerical value!\n\n";
    } else {
      input = std::stof(input_string1);
    }
  } while (valid_input1 == false);
  
  return input;
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
     std::cout<<" ------ this is the circuit digram---- \n";
    std::cout<<"\t\t\t|\t|\n";
  std::cout<<"——————————— |\t| ————————————————————————O\n";
  std::cout<<"\t\t\t|\t|\t\t\t| |\n";
  std::cout<<"\t\t\t\t\t\t\t| |\n";
  std::cout<<"\t\t\t\t\t\t   ——————\t\t\n";
  std::cout<<"\t\t\t\t\t\t   |\t|\t\t\n";
  std::cout<<"\t\t\t\t\t\t   |\t|\t\tV\n";
  std::cout<<"\t\t\t\t\t\t   ——————\t\tout\n";
  std::cout<<"\t\t\t\t\t\t\t| |\n";
  std::cout<<"\t\t\t\t\t\t\t| |\n";
    std::cout<<"————————————————————————————————————————O\n";
    
 std::cout<<"choose from the menu above ";
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
  std::cout<<"Input the resistor value : ";
   resistor = waituntilvalidnum2();
    std::cout<<"Input the capacitor value : ";
   capacitor = waituntilvalidnum2();
  cutoff_frequency = 1/(2*pi*resistor*capacitor);
  std::cout<<"cut off frequency ="<<cutoff_frequency;
  storage_check();
}
    
void filtermenu :: submenu1_item_2(){
std::cout<<"Input the resistor value : ";
   resistor = waituntilvalidnum2();
    std::cout<<"Input the capacitor value : ";
   capacitor = waituntilvalidnum2();
  std::cout<<"Input the frequency : ";
   frequency = waituntilvalidnum2();
  double subgain1 = 2*pi*frequency*resistor*capacitor;
  double subgain2=pow(subgain1,2);
  gain =  2*pi*frequency*resistor*capacitor/
  pow(1+subgain2,1/2);
  std::cout<<"gain="<<gain;
  storage_check();
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
      std::cout << "--------------------------------------------------------\n";
      std::cout<<" ------ this is the circuit digram ------\n";
    std::cout<<"\t\t\t————\n";
  std::cout<<"———————————|\t|————————————————————————O\n";
  std::cout<<"\t\t\t————\t\t\t| |\n";
  std::cout<<"\t\t\t\t\t\t\t| |\n";
  std::cout<<"\t\t\t\t\t\t —————————\t\tV\n";
  std::cout<<"\t\t\t\t\t\t —————————\t\tout\n";
  std::cout<<"\t\t\t\t\t\t\t| |\n";
  std::cout<<"\t\t\t\t\t\t\t| |\n";
    std::cout<<"————————————————————————————————————————O\n";
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
  std::cout<<"Input the resistor value : ";
   resistor = waituntilvalidnum2();
    std::cout<<"Input the capacitor value : ";
   capacitor = waituntilvalidnum2();
  cutoff_frequency = 1/(2*pi*resistor*capacitor);
  std::cout<<"cut off frequency ="<<cutoff_frequency;
  storage_check();
}
    
void filtermenu :: submenu2_item_2(){
std::cout<<"Input the resistor value : ";
   resistor = waituntilvalidnum2();
    std::cout<<"Input the capacitor value : ";
   capacitor = waituntilvalidnum2();
  std::cout<<"Input the frequency : ";
   frequency = waituntilvalidnum2();
  double subgain1 = 2*pi*frequency*resistor*capacitor;
  double subgain2=pow(subgain1,2);
  gain =  1/pow(1+subgain2,1/2);
  std::cout<<"gain="<<gain;
  storage_check();
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
  std::cout<<"choose from the menu above ";
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
  std::cout<<"Input the resistor value :";
   resistor = waituntilvalidnum2();
    std::cout<<"Input the inductor value :";
   inductor = waituntilvalidnum2();
  cutoff_frequency = resistor/(2*pi*inductor);
  std::cout<<"cut off frequency ="<<cutoff_frequency;
  storage_check();
}
    
void filtermenu :: submenu3_item_2(){
std::cout<<"Input the resistor value : ";
   resistor = waituntilvalidnum2();
    std::cout<<"Input the capacitor value : ";
   inductor = waituntilvalidnum2();
  std::cout<<"Input the frequency : ";
   frequency = waituntilvalidnum2();
  double subgain1=pow(resistor,2);
  double subgain2 = pow(2*pi*frequency*inductor,2);
  double subgain3 = pow(subgain1+subgain2,1/2);
  gain =resistor/subgain3  ;
  std::cout<<"gain="<<gain;
  storage_check();
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
 std::cout<<"choose from the menu above ";
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
  std::cout<<"Input the resistor value : ";
   resistor = waituntilvalidnum2();
    std::cout<<"Input the capacitor value : ";
   inductor = waituntilvalidnum2();
  std::cout<<"Input the inductor value : ";
   inductor = waituntilvalidnum2();
  double subfrequency = pow(capacitor*inductor,1/2);
  
  cutoff_frequency =1/2*pi*subfrequency ;
  std::cout<<"center of passband = "<<cutoff_frequency;
  storage_check();
}
    
void filtermenu :: submenu4_item_2(){
std::cout<<"Input the resistor value : ";
   resistor = waituntilvalidnum2();
    std::cout<<"Input the capacitor value : ";
   capacitor = waituntilvalidnum2();
  std::cout<<"Input the inductor value : ";
   inductor = waituntilvalidnum2();
  std::cout<<"Input the frequency : ";
   frequency = waituntilvalidnum2();
  double subgain1=2*pi*frequency*inductor;
  double subgain2 = 1/(2*pi*frequency*capacitor);
  gain =resistor/(resistor*subgain1*subgain2);
  std::cout<<"gain="<<gain;
  storage_check();}

void filtermenu:: menu_item_5(){
  std::cout<<"\n Choose the order of the calculation you want to view ";
input=waituntilvalidnum();
  if(input>10||input<1) {std::cout<<"the maximum stored values are 10, please eneter an integer between 1 and 10";
   menu_item_5();
    }
  double *ptrr = &resistor_array[input-1];
  double *ptrc = &capacitor_array[input-1];
  double *ptrf= &frequency_array[input-1];
  double *ptri=&inductor_array[input-1];
  double*ptrcf=&frequencyresult[input-1];
  double*ptrg=&gainresult[input-1];
std::cout<<"The calculation order "<<input<<" is: ";
  std::cout<<"\n resistor : "<<*ptrr;
  std::cout<<"\n capacitor : "<<*ptrc;
  std::cout<<"\n frequency : "<<*ptrf;
  std::cout<<"\n inductor : "<<*ptri;
  std::cout<<"\n cut off frequency : "<<*ptrcf;
  std::cout<<"\n gain : "<<*ptrg;
  go_back_to_filter();
}