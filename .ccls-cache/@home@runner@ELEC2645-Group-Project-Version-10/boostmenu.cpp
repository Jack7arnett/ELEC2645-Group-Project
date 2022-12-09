#include "boostmenu.h"

void Boostmenu::boost_converter() {
  std::cout << "\n------------- Boost Converter Menu --------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Switching Frequency\t\t\t\t\t\t|\n";
  std::cout << "|\t2. Time period\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t3. Power in\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t4. Power out\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t5. Duty ratio (4 equations)\t\t\t\t\t|\n";
  std::cout << "|\t6. Inductor\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t7. Current ripple magnitude\t\t\t\t\t|\n";
  std::cout << "|\t8. Capacitor (3 equations)\t\t\t\t\t|\n";
  std::cout << "|\t9. Voltage ripple magnitude (2 equations)\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-------------------------------------------------\n";
  std::cout << "\nPlease choose a desired calculation.\n";
  int yourchoice;
  std::cin >> yourchoice;
switch (yourchoice)
{ 
case 1: boost_eq_1(); break;
case 2: boost_eq_2();break;
case 3: boost_eq_3(); break;
case 4: boost_eq_4();break;
case 5: boost_eq_5(); break;
case 6: boost_eq_6();break;
case 7: boost_eq_7(); break;
case 8: boost_eq_8();break;
case 9: boost_eq_9();break;
default: std::cout <<"invalid"; break;
  }
}

void Boostmenu::boost_eq_1(){
  std::cout << "Equation 1 boost thjglf" << std::endl;
}

void Boostmenu::boost_eq_2(){
  std::cout << "Equation 2" << std::endl;
}

void Boostmenu::boost_eq_3(){
  std::cout << "Equation 3" << std::endl;
}

void Boostmenu::boost_eq_4(){
  std::cout << "Equation 4" << std::endl;
}

void Boostmenu::boost_eq_5(){
  std::cout << "Equation 5" << std::endl;
}

void Boostmenu::boost_eq_6(){
  std::cout << "Equation 6" << std::endl;
}

void Boostmenu::boost_eq_7(){
  std::cout << "Equation 7" << std::endl;
}

void Boostmenu::boost_eq_8(){
  std::cout << "Equation 8" << std::endl;
}

void Boostmenu::boost_eq_9(){
  std::cout << "Equation 9" << std::endl;
}