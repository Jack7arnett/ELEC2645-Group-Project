#include "buckmenu.h"
#include "generalfunctions.h"

void Buckmenu::buck_converter() {
  Func clr;
  clr.clear();
  print_buck_menu();
  Func check;
  int yourchoice = check.waituntilvalidnum(9);
switch (yourchoice)
{ 
case 1: buck_eq_1(); break;
case 2: buck_eq_2();break;
case 3: buck_eq_3(); break;
case 4: buck_eq_4();break;
case 5: buck_eq_5(); break;
case 6: buck_eq_6();break;
case 7: buck_eq_7(); break;
case 8: buck_eq_8();break;
case 9: buck_eq_9();break;
default: std::cout <<"invalid"; break;
  }
}

void Buckmenu::print_buck_menu() {
  std::cout << "\n------------- Buck Converter Menu --------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Switching Frequency\t\t\t\t\t\t|\n";
  std::cout << "|\t2. Time period\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t3. Power in\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t4. Power out\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t5. Duty ratio (4 equations)\t\t\t\t\t|\n";
  std::cout << "|\t6. Inductor\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t7. Current ripple magnitude\t\t\t\t\t|\n";
  std::cout << "|\t8. Capacitor\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t9. Voltage ripple magnitude (2 equations)\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "------------------------------------------------\n";
  std::cout << "\nPlease choose a desired calculation.\n";
  std::cout << "\nSelect item: ";
}

void Buckmenu::buck_eq_1(){
  Func clr;
  clr.clear();
  std::cout << "\nSwitching frequency (Fs) selected:\n" << std::endl;
  std::cout << "Fs = 1/Ts\n" << std::endl;
  std::cout << "Please enter a value for the time period (Ts).\n" << std::endl;
  float Fs;
  float Ts;
  std::cin >> Ts;
  Fs = 1/Ts;
  std::cout << "\nSwitching frequency = " << Fs << " s.\n";
}

void Buckmenu::buck_eq_2(){
  Func clr;
  clr.clear();
  std::cout << "\nTime period (Ts) selected:\n" << std::endl;
  std::cout << "Ts = t(on) + t(off)\n" << std::endl;
  std::cout << "Please enter a value for t(on).\n" << std::endl;
  float Ts;
  float ton;
  std::cin >> ton;
  std::cout << "\nPlease enter a value for t(off).\n" << std::endl;
  float toff;
  std::cin >> toff;
  Ts = ton + toff;
  std::cout << "\nTime period = " << Ts << " s.\n";
}

void Buckmenu::buck_eq_3(){
  Func clr;
  clr.clear();
  std::cout << "\nPower in (Pin) selected:\n" << std::endl;
  std::cout << "Pin = Vi + Ii\n" << std::endl;
  std::cout << "Please enter a value for voltage in (Vi).\n" << std::endl;
  float Pin;
  float Vi;
  std::cin >> Vi;
  std::cout << "\nPlease enter a value for current in (Ii).\n" << std::endl;
  float Ii;
  std::cin >> Ii;
  Pin = Vi + Ii;
  std::cout << "\nPower in = " << Pin << " W.\n";
}

void Buckmenu::buck_eq_4(){
  Func clr;
  clr.clear();
  std::cout << "\nPower out (Pout) selected:\n" << std::endl;
  std::cout << "Pout = Vo + Io\n" << std::endl;
  std::cout << "Please enter a value for voltage out (Vo).\n" << std::endl;
  float Pout;
  float Vo;
  std::cin >> Vo;
  std::cout << "\nPlease enter a value for current out (Io).\n" << std::endl;
  float Io;
  std::cin >> Io;
  Pout = Vo + Io;
  std::cout << "\nPower in = " << Pout << " W.\n";
}

void Buckmenu::buck_eq_5(){
  Func clr;
  clr.clear();
  print_duty_menu();
  Func check;
  int yourchoice = check.waituntilvalidnum(4);
switch (yourchoice)
{ 
case 1: duty_eq_1(); break;
case 2: duty_eq_2();break;
case 3: duty_eq_3(); break;
case 4: duty_eq_4();break;
default: std::cout <<"invalid"; break;
  }
}

void Buckmenu::buck_eq_6(){
  Func clr;
  clr.clear();
  std::cout << "\nInductor (L) selected:\n" << std::endl;
  std::cout << "L = (1-K)Vo/(Fs x Δi)\n" << std::endl;
  std::cout << "Please enter a value for duty ratio (K).\n" << std::endl;
  float L;
  float K;
  std::cin >> K;
  std::cout << "\nPlease enter a value for voltage out (Vo).\n" << std::endl;
  float Vo;
  std::cin >> Vo;
  std::cout << "\nPlease enter a value for switching frequency (Fs).\n" << std::endl;
  float Fs;
  std::cin >> Fs;
  std::cout << "\nPlease enter a value for current ripple magnitude (Δi).\n" << std::endl;
  float i;
  std::cin >> i;
  L = ((1-K)*Vo)/(Fs*i);
  std::cout << "\nInductor value = " << L << " SI.\n";
}

void Buckmenu::buck_eq_7(){
  Func clr;
  clr.clear();
  std::cout << "\nCurrent ripple magnitude (Δi) selected:\n" << std::endl;
  std::cout << "Δi = ((1-K)Ts x Vo)/L\n" << std::endl;
  std::cout << "Please enter a value for duty ratio (K).\n" << std::endl;
  float i;
  float K;
  std::cin >> K;
  std::cout << "\nPlease enter a value for time period (Ts).\n" << std::endl;
  float Ts;
  std::cin >> Ts;
  std::cout << "\nPlease enter a value for voltage out (Vo).\n" << std::endl;
  float Vo;
  std::cin >> Vo;
  std::cout << "\nPlease enter a value for the inductor (L).\n" << std::endl;
  float L;
  std::cin >> L;
  i = ((1-K)*Ts*Vo)/L;
  std::cout << "\nCurrent ripple magnitude = " << i << " A.\n";
}

void Buckmenu::buck_eq_8(){
  Func clr;
  clr.clear();
  std::cout << "\nCapacitor (Co) selected:\n" << std::endl;
  std::cout << "Co = (1-K)Vo/(8 x (Fs)^2 x Δvo x L)\n" << std::endl;
  std::cout << "Please enter a value for duty ratio (K).\n" << std::endl;
  float Co;
  float Q;
  float K;
  std::cin >> K;
  std::cout << "\nPlease enter a value for voltage out (Vo).\n" << std::endl;
  float Vo;
  std::cin >> Vo;
  std::cout << "\nPlease enter a value for switching frequency (Fs).\n" << std::endl;
  float Fs;
  std::cin >> Fs;
  std::cout << "\nPlease enter a value for current ripple magnitude (Δvo).\n" << std::endl;
  float vo;
  std::cin >> vo;
  std::cout << "\nPlease enter a value for the inductor (L).\n" << std::endl;
  float L;
  std::cin >> L;
  capacitor_calc(K, Vo, Fs, vo, L, Co, Q);
  std::cout << "\nCapacitor = " << Co << " F.\n";
  std::cout << "\nCharge of Capacitor = " << Q << " C.\n";
}

void Buckmenu::capacitor_calc(float K, float Vo, float Fs, float vo, float L, float &Co, float &Q){
  Co = ((1-K)*Vo)/(8*pow(Fs,2)*vo*L);
  Q = Co*vo;
}

void Buckmenu::buck_eq_9(){
  Func clr;
  clr.clear();
  print_volt_menu();
  Func check;
  int yourchoice = check.waituntilvalidnum(2);
switch (yourchoice)
{ 
case 1: voltrip_eq_1(); break;
case 2: voltrip_eq_2();break;
default: std::cout <<"invalid"; break;
  }
}

void Buckmenu::print_duty_menu(){
  std::cout << "\n-------- Duty Ratio (K) Equation Menu ----------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. K = t(on)/Ts\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t2. K = 1-(t(off)/Ts)\t\t\t\t\t\t|\n";
  std::cout << "|\t3. K = Vo/Vi\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t4. K = Ii/Io\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "------------------------------------------------\n";
  std::cout << "\nPlease select an equation for the duty ratio.\n";
  std::cout << "\nSelect item: ";
}

void Buckmenu::duty_eq_1(){
  Func clr;
  clr.clear();
  std::cout << "\nDuty ratio equation 1 selected:\n" << std::endl;
  std::cout << "K = t(on)/Ts\n" << std::endl;
  std::cout << "Please enter a value for t(on).\n" << std::endl;
  float K;
  float ton;
  std::cin >> ton;
  std::cout << "\nPlease enter a value for Ts.\n" << std::endl;
  float Ts;
  std::cin >> Ts;
  K = ton/Ts;
  std::cout << "\nDuty ratio = " << K << "\n";
}

void Buckmenu::duty_eq_2(){
  Func clr;
  clr.clear();
  std::cout << "\nDuty ratio equation 2 selected:\n" << std::endl;
  std::cout << "K = 1-(t(off)/Ts)\n" << std::endl;
  std::cout << "Please enter a value for t(off).\n" << std::endl;
  float K;
  float toff;
  std::cin >> toff;
  std::cout << "\nPlease enter a value for Ts.\n" << std::endl;
  float Ts;
  std::cin >> Ts;
  K = 1-(toff/Ts);
  std::cout << "\nDuty ratio = " << K << "\n";
}

void Buckmenu::duty_eq_3(){
  Func clr;
  clr.clear();
  std::cout << "\nDuty ratio equation 3 selected:\n" << std::endl;
  std::cout << "K = Vo/Vi\n" << std::endl;
  std::cout << "Please enter a value for Vo.\n" << std::endl;
  float K;
  float Vo;
  std::cin >> Vo;
  std::cout << "\nPlease enter a value for Vi.\n" << std::endl;
  float Vi;
  std::cin >> Vi;
  K = Vo/Vi;
  std::cout << "\nDuty ratio = " << K << "\n";
}

void Buckmenu::duty_eq_4(){
  Func clr;
  clr.clear();
  std::cout << "\nDuty ratio equation 4 selected:\n" << std::endl;
  std::cout << "K = Ii/Io\n" << std::endl;
  std::cout << "Please enter a value for Ii.\n" << std::endl;
  float K;
  float Ii;
  std::cin >> Ii;
  std::cout << "\nPlease enter a value for Io.\n" << std::endl;
  float Io;
  std::cin >> Io;
  K = Ii/Io;
  std::cout << "\nDuty ratio = " << K << "\n";
}

void Buckmenu::print_volt_menu(){
  std::cout << "\n- Voltage Ripple Magnitude (Δvo) Equation Menu -\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Δvo = (% x Vo)/100\t\t\t\t\t\t|\n";
  std::cout << "|\t2. Δvo = (K x Ts)/(R x Co)\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "------------------------------------------------\n";
  std::cout << "\nPlease select an equation for the voltage ripple magnitude.\n";
  std::cout << "\nSelect item: ";
}

void Buckmenu::voltrip_eq_1(){
  Func clr;
  clr.clear();
  std::cout << "\nVoltage ripple magnitude equation 1 selected:\n" << std::endl;
  std::cout << "Δvo = (% x Vo)/100\n" << std::endl;
  std::cout << "Please enter a value for the voltage ripple magnitude percentage.\n" << std::endl;
  float vo;
  float perc;
  std::cin >> perc;
  std::cout << "\nPlease enter a value for Vo.\n" << std::endl;
  float Vo;
  std::cin >> Vo;
  vo = (perc*Vo)/100;
  std::cout << "\nVoltage ripple magnitude = " << vo << "\n";
}

void Buckmenu::voltrip_eq_2(){
  Func clr;
  clr.clear();
  std::cout << "\nVoltage ripple magnitude equation 2 selected:\n" << std::endl;
  std::cout << "Δvo = (K x Ts)/(R x Co)\n" << std::endl;
  std::cout << "Please enter a value for the duty ratio.\n" << std::endl;
  float vo;
  float K;
  std::cin >> K;
  std::cout << "\nPlease enter a value for Ts.\n" << std::endl;
  float Ts;
  std::cin >> Ts;
  std::cout << "Please enter a value for the resistor.\n" << std::endl;
  float R;
  std::cin >> R;
  std::cout << "\nPlease enter a value for the capacitor.\n" << std::endl;
  float Co;
  std::cin >> Co;
  vo = (K*Ts)/(R*Co);
  std::cout << "\nVoltage ripple magnitude = " << vo << "\n";
}