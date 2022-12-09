#include "boostmenu.h"
#include "generalfunctions.h"

void Boostmenu::boost_converter() {
  Func clr;
  clr.clear();
  print_boost_menu();
  Func check;
  int yourchoice = check.checkmenuinput(9);
  select_boost_item(yourchoice);
}

void Boostmenu::print_boost_menu(){
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
}

void Boostmenu::select_boost_item(int input){
  switch (input)
{ case 1: boost_eq_1();break;
  case 2: boost_eq_2();break;
  case 3: boost_eq_3();break;
  case 4: boost_eq_4();break;
  case 5: boost_eq_5();break;
  case 6: boost_eq_6();break;
  case 7: boost_eq_7();break;
  case 8: boost_eq_8();break;
  case 9: boost_eq_9();break;
  default: std::cout <<"invalid"; break;
  }
}

void Boostmenu::boost_eq_1(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nSwitching frequency (Fs) selected:\n" << std::endl;
  std::cout << "Fs = 1/Ts\n" << std::endl;
  std::cout << "Please enter a value for the time period (Ts).\n" << std::endl;
  float Fs;
  float Ts = valcheck.checkvalinput();
  Fs = 1/Ts;
  std::cout << "\nSwitching frequency = " << Fs << " s.\n";
}

void Boostmenu::boost_eq_2(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nTime period (Ts) selected:\n" << std::endl;
  std::cout << "Ts = t(on) + t(off)\n" << std::endl;
  std::cout << "Please enter a value for t(on).\n" << std::endl;
  float Ts;
  float ton = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for t(off).\n" << std::endl;
  float toff = valcheck.checkvalinput();
  Ts = ton + toff;
  std::cout << "\nTime period = " << Ts << " s.\n";
}

void Boostmenu::boost_eq_3(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nPower in (Pin) selected:\n" << std::endl;
  std::cout << "Pin = Vi + Ii\n" << std::endl;
  std::cout << "Please enter a value for voltage in (Vi).\n" << std::endl;
  float Pin;
  float Vi = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current in (Ii).\n" << std::endl;
  float Ii = valcheck.checkvalinput();
  Pin = Vi + Ii;
  std::cout << "\nPower in = " << Pin << " W.\n";
}

void Boostmenu::boost_eq_4(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nPower out (Pout) selected:\n" << std::endl;
  std::cout << "Pout = Vo + Io\n" << std::endl;
  std::cout << "Please enter a value for voltage out (Vo).\n" << std::endl;
  float Pout;
  float Vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current out (Io).\n" << std::endl;
  float Io = valcheck.checkvalinput();
  Pout = Vo + Io;
  std::cout << "\nPower out = " << Pout << " W.\n";
}

void Boostmenu::boost_eq_5(){
  std::cout << "Equation 5" << std::endl;
}

void Boostmenu::boost_eq_6(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nInductor (L) selected:\n" << std::endl;
  std::cout << "L = (Vi x K)/(Fs x Δi)\n" << std::endl;
  std::cout << "Please enter a value for duty ratio (K).\n" << std::endl;
  float L;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for voltage in (Vi).\n" << std::endl;
  float Vi = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for switching frequency (Fs).\n" << std::endl;
  float Fs = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current ripple magnitude (Δi).\n" << std::endl;
  float i = valcheck.checkvalinput();
  L = (K*Vi)/(Fs*i);
  std::cout << "\nInductor value = " << L << " SI.\n";
}

void Boostmenu::boost_eq_7(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nCurrent ripple magnitude (Δi) selected:\n" << std::endl;
  std::cout << "Δi = (K x Ts x Vi)/L\n" << std::endl;
  std::cout << "Please enter a value for duty ratio (K).\n" << std::endl;
  float i;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for time period (Ts).\n" << std::endl;
  float Ts = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for voltage in (Vi).\n" << std::endl;
  float Vi = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the inductor (L).\n" << std::endl;
  float L = valcheck.checkvalinput();
  i = (K*Ts*Vi)/L;
  std::cout << "\nCurrent ripple magnitude = " << i << " A.\n";
}

void Boostmenu::boost_eq_8(){
  std::cout << "Equation 8" << std::endl;
}

void Boostmenu::boost_eq_9(){
  std::cout << "Equation 9" << std::endl;
}