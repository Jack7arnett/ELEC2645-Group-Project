#include "buckmenu.h"
#include "generalfunctions.h"

void Buckmenu::buck_converter() {
  Func clr;
  clr.clear();
  print_buck_menu();
  Func check;
  int yourchoice = check.checkmenuinput(10);
  select_buck_item(yourchoice);
}

void Buckmenu::print_buck_menu() {
    std::cout << "--------Buck Converter Diagram--------" << std::endl;
  std::cout << "|                                    |" << std::endl;
  std::cout << "|  (+)__________                     |" << std::endl;
  std::cout << "|   |          |                     |" << std::endl;
  std::cout << "|   |          S                     |" << std::endl;
  std::cout << "|  Vi          |____L______________  |" << std::endl;
  std::cout << "|   |          |         |        |  |" << std::endl;
  std::cout << "|   |          D         C        R  |" << std::endl;
  std::cout << "|  (-)_________|_________|________|  |" << std::endl;
  std::cout << "|                                    |" << std::endl;
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "\n------------- Buck Converter Menu ---------------\n";
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
  std::cout << "|\t10. Return\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-------------------------------------------------\n";
  std::cout << "\nPlease choose a desired calculation.\n";
  std::cout << "\nSelect item: ";
}

void Buckmenu::select_buck_item(int input){
  Mainmenu main;
  switch(input)
{ case 1: buck_eq_1(); break;
  case 2: buck_eq_2();break;
  case 3: buck_eq_3(); break;
  case 4: buck_eq_4();break;
  case 5: buck_eq_5(); break;
  case 6: buck_eq_6();break;
  case 7: buck_eq_7(); break;
  case 8: buck_eq_8();break;
  case 9: buck_eq_9();break;
  case 10: main.menu_item_1();;break;
  default: std::cout <<"invalid"; break;
  }
}


void Buckmenu::buck_eq_1(){
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

void Buckmenu::buck_eq_2(){
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

void Buckmenu::buck_eq_3(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nPower in (Pin) selected:\n" << std::endl;
  std::cout << "Pin = Vi x Ii\n" << std::endl;
  std::cout << "Please enter a value for voltage in (Vi).\n" << std::endl;
  float Pin;
  float Vi = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current in (Ii).\n" << std::endl;
  float Ii = valcheck.checkvalinput();
  Pin = Vi*Ii;
  std::cout << "\nPower in = " << Pin << " W.\n";
}

void Buckmenu::buck_eq_4(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nPower out (Pout) selected:\n" << std::endl;
  std::cout << "Pout = Vo x Io\n" << std::endl;
  std::cout << "Please enter a value for voltage out (Vo).\n" << std::endl;
  float Pout;
  float Vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current out (Io).\n" << std::endl;
  float Io = valcheck.checkvalinput();
  Pout = Vo*Io;
  std::cout << "\nPower out = " << Pout << " W.\n";
}

//code relating to duty ratio menu begins here

void Buckmenu::buck_eq_5(){
  Func clr;
  clr.clear();
  print_duty_menu();
  Func check;
  int yourchoice = check.checkmenuinput(5);
  select_duty_item(yourchoice);
}

void Buckmenu::select_duty_item(int input){
  switch (input)
{ case 1: duty_eq_1(); break;
  case 2: duty_eq_2();break;
  case 3: duty_eq_3(); break;
  case 4: duty_eq_4();break;
  case 5: buck_converter();break;
  default: std::cout <<"invalid"; break;
  }
}

void Buckmenu::print_duty_menu(){
  std::cout << "\n--------- Duty Ratio (K) Equation Menu ----------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. K = t(on)/Ts\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t2. K = 1-(t(off)/Ts)\t\t\t\t\t\t|\n";
  std::cout << "|\t3. K = Vo/Vi\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t4. K = Ii/Io\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t5. Return\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-------------------------------------------------\n";
  std::cout << "\nPlease select an equation for the duty ratio.\n";
  std::cout << "\nSelect item: ";
}

void Buckmenu::duty_eq_1(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nDuty ratio equation 1 selected:\n" << std::endl;
  std::cout << "K = t(on)/Ts\n" << std::endl;
  std::cout << "Please enter a value for t(on).\n" << std::endl;
  float K;
  float ton = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for Ts.\n" << std::endl;
  float Ts = valcheck.checkvalinput();
  K = ton/Ts;
  std::cout << "\nDuty ratio = " << K << "\n";
}

void Buckmenu::duty_eq_2(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nDuty ratio equation 2 selected:\n" << std::endl;
  std::cout << "K = 1-(t(off)/Ts)\n" << std::endl;
  std::cout << "Please enter a value for t(off).\n" << std::endl;
  float K;
  float toff = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for Ts.\n" << std::endl;
  float Ts = valcheck.checkvalinput();
  K = 1-(toff/Ts);
  std::cout << "\nDuty ratio = " << K << "\n";
}

void Buckmenu::duty_eq_3(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nDuty ratio equation 3 selected:\n" << std::endl;
  std::cout << "K = Vo/Vi\n" << std::endl;
  std::cout << "Please enter a value for Vo.\n" << std::endl;
  float K;
  float Vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for Vi.\n" << std::endl;
  float Vi = valcheck.checkvalinput();
  K = Vo/Vi;
  std::cout << "\nDuty ratio = " << K << "\n";
}

void Buckmenu::duty_eq_4(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nDuty ratio equation 4 selected:\n" << std::endl;
  std::cout << "K = Ii/Io\n" << std::endl;
  std::cout << "Please enter a value for Ii.\n" << std::endl;
  float K;
  float Ii = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for Io.\n" << std::endl;
  float Io = valcheck.checkvalinput();
  K = Ii/Io;
  std::cout << "\nDuty ratio = " << K << "\n";
}

//code relating to duty ratio menu ends here

void Buckmenu::buck_eq_6(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nInductor (L) selected:\n" << std::endl;
  std::cout << "L = (1-K)Vo/(Fs x Δi)\n" << std::endl;
  std::cout << "Please enter a value for duty ratio (K).\n" << std::endl;
  float L;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for voltage out (Vo).\n" << std::endl;
  float Vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for switching frequency (Fs).\n" << std::endl;
  float Fs = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current ripple magnitude (Δi).\n" << std::endl;
  float i = valcheck.checkvalinput();
  L = ((1-K)*Vo)/(Fs*i);
  std::cout << "\nInductor value = " << L << " SI.\n";
}

void Buckmenu::buck_eq_7(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nCurrent ripple magnitude (Δi) selected:\n" << std::endl;
  std::cout << "Δi = ((1-K)Ts x Vo)/L\n" << std::endl;
  std::cout << "Please enter a value for duty ratio (K).\n" << std::endl;
  float i;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for time period (Ts).\n" << std::endl;
  float Ts = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for voltage out (Vo).\n" << std::endl;
  float Vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the inductor (L).\n" << std::endl;
  float L = valcheck.checkvalinput();
  i = ((1-K)*Ts*Vo)/L;
  std::cout << "\nCurrent ripple magnitude = " << i << " A.\n";
}

void Buckmenu::buck_eq_8(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nCapacitor (Co) selected:\n" << std::endl;
  std::cout << "Co = (1-K)Vo/(8 x (Fs)^2 x Δvo x L)\n" << std::endl;
  std::cout << "Please enter a value for duty ratio (K).\n" << std::endl;
  float Co;
  float Q;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for voltage out (Vo).\n" << std::endl;
  float Vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for switching frequency (Fs).\n" << std::endl;
  float Fs = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current ripple magnitude (Δvo).\n" << std::endl;
  float vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the inductor (L).\n" << std::endl;
  float L = valcheck.checkvalinput();
  capacitor_calc(K, Vo, Fs, vo, L, Co, Q);
  std::cout << "\nCapacitor = " << Co << " F.\n";
  std::cout << "\nCharge of Capacitor = " << Q << " C.\n";
}

void Buckmenu::capacitor_calc(float K, float Vo, float Fs, float vo, float L, float &Co, float &Q){
  Co = ((1-K)*Vo)/(8*pow(Fs,2)*vo*L);
  Q = Co*vo;
}

//code relating to volt menu begins here

void Buckmenu::buck_eq_9(){
  Func clr;
  clr.clear();
  print_volt_menu();
  Func check;
  int yourchoice = check.checkmenuinput(3);
  select_volt_item(yourchoice);
}

void Buckmenu::select_volt_item(int input){
  switch (input)
{ case 1: voltrip_eq_1(); break;
  case 2: voltrip_eq_2();break;
  case 3: buck_converter();break;
  default: std::cout <<"invalid"; break;
  }
}

void Buckmenu::print_volt_menu(){
  std::cout << "\n- Voltage Ripple Magnitude (Δvo) Equation Menu -\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t   |\n";
  std::cout << "|\t1. Δvo = (1-K)Vo/(8 x Co x L x (Fs)^2)\t   |\n";
  std::cout << "|\t2. Δvo = π(1-K)(Fc)^2/(2 x (Fs)^2)\t\t   |\n";
  std::cout << "|\t3. Return\t\t\t\t\t\t\t\t   |\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t   |\n";
  std::cout << "------------------------------------------------\n";
  std::cout << "\nPlease select an equation for the voltage ripple magnitude.\n";
  std::cout << "\nSelect item: ";
}

void Buckmenu::voltrip_eq_1(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nVoltage ripple magnitude equation 1 selected:\n" << std::endl;
  std::cout << "Δvo = (1-K)Vo/(8 x Co x L x (Fs)^2)\n" << std::endl;
  std::cout << "Please enter a value for the duty ratio (K).\n" << std::endl;
  float vo;
  float K = valcheck.checkvalinput();
  std::cout << "Please enter a value for voltage out (Vo).\n" << std::endl;
  float Vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the capacitor (Co).\n" << std::endl;
  float Co = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the inductor (L).\n" << std::endl;
  float L = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the switching frequency (Fs).\n" << std::endl;
  float Fs = valcheck.checkvalinput();
  vo = ((1-K)*Vo)/(8*Co*L*pow(Fs,2));
  std::cout << "\nVoltage ripple magnitude = " << vo << "\n";
}

void Buckmenu::voltrip_eq_2(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nVoltage ripple magnitude equation 2 selected:\n" << std::endl;
  std::cout << "Δvo = π(1-K)(Fc)^2/(2 x (Fs)^2)\n" << std::endl;
  std::cout << "Please enter a value for the duty ratio.\n" << std::endl;
  float vo;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the corner frequency (Fc).\n" << std::endl;
  float Fc = valcheck.checkvalinput();
  std::cout << "Please enter a value for the switching frequency (Fs).\n" << std::endl;
  float Fs = valcheck.checkvalinput();
  vo = (M_PI*(1-K)*pow(Fc,2))/(2*pow(Fs,2));
  std::cout << "\nVoltage ripple magnitude = " << vo << "\n";
}

//code relating to volt menu ends here