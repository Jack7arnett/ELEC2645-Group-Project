#include "boostmenu.h"
#include "generalfunctions.h"

void Boostmenu::boost_converter() {
  Func clr;
  clr.clear();
  print_boost_menu();
  Func check;
  int yourchoice = check.checkmenuinput(11);
  select_boost_item(yourchoice);
}

void Boostmenu::print_boost_menu(){
  std::cout << "-------Boost Converter Diagram--------" << std::endl;
  std::cout << "|                                    |" << std::endl;
  std::cout << "|  (+)____L_________D______________  |" << std::endl;
  std::cout << "|   |          |         |        |  |" << std::endl;
  std::cout << "|   |          |         |        |  |" << std::endl;
  std::cout << "|  Vi          S         C        R  |" << std::endl;
  std::cout << "|   |          |         |        |  |" << std::endl;
  std::cout << "|   |          |         |        |  |" << std::endl;
  std::cout << "|  (-)_________|_________|________|  |" << std::endl;
  std::cout << "|                                    |" << std::endl;
  std::cout << "--------------------------------------" << std::endl;
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
  std::cout << "|\t10. Calculation history\t\t\t\t\t\t|\n";
  std::cout << "|\t11. Return \t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-------------------------------------------------\n";
  std::cout << "\nPlease choose a desired calculation.\n";
}

void Boostmenu::select_boost_item(int input){
  Mainmenu main;
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
  case 10: calc_hist();break;
  case 11: main.menu_item_1();;break;
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
  float Ts = valcheck.checkvalinput();
  Fs = 1/Ts;
  std::cout << "\nSwitching frequency = " << Fs << " s.\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::boost_eq_2(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nTime period (Ts) selected:\n" << std::endl;
  std::cout << "Ts = t(on) + t(off)\n" << std::endl;
  std::cout << "Please enter a value for t(on).\n" << std::endl;
  float ton = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for t(off).\n" << std::endl;
  float toff = valcheck.checkvalinput();
  Ts = ton + toff;
  std::cout << "\nTime period = " << Ts << " s.\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::boost_eq_3(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nPower in (Pin) selected:\n" << std::endl;
  std::cout << "Pin = Vi x Ii\n" << std::endl;
  std::cout << "Please enter a value for voltage in (Vi).\n" << std::endl;
  float Vi = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current in (Ii).\n" << std::endl;
  float Ii = valcheck.checkvalinput();
  Pin = Vi*Ii;
  std::cout << "\nPower in = " << Pin << " W.\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::boost_eq_4(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nPower out (Pout) selected:\n" << std::endl;
  std::cout << "Pout = Vo x Io\n" << std::endl;
  std::cout << "Please enter a value for voltage out (Vo).\n" << std::endl;
  float Vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current out (Io).\n" << std::endl;
  float Io = valcheck.checkvalinput();
  Pout = Vo*Io;
  std::cout << "\nPower out = " << Pout << " W.\n";
  storage_check();
  go_back_to_boost();
}

//code relating to duty ratio menu begins here

void Boostmenu::boost_eq_5(){
  Func clr;
  clr.clear();
  print_duty_menu();
  Func check;
  int yourchoice = check.checkmenuinput(5);
  select_duty_item(yourchoice);
}

void Boostmenu::select_duty_item(int input){
  switch (input)
{ case 1: duty_eq_1(); break;
  case 2: duty_eq_2();break;
  case 3: duty_eq_3(); break;
  case 4: duty_eq_4();break;
  case 5: boost_converter();break;
  default: std::cout <<"invalid"; break;
  }
}

void Boostmenu::print_duty_menu(){
  std::cout << "\n---------- Duty Ratio (K) Equation Menu ---------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. K = t(on)/Ts\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t2. K = 1-(t(off)/Ts)\t\t\t\t\t\t|\n";
  std::cout << "|\t3. K = 1-(Vi/Vo)\t\t\t\t\t\t\t|\n";
  std::cout << "|\t4. K = 1-(Io/Ii)\t\t\t\t\t\t\t|\n";
  std::cout << "|\t5. Return\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-------------------------------------------------\n";
  std::cout << "\nPlease select an equation for the duty ratio.\n";
  std::cout << "\nSelect item: ";
}

void Boostmenu::duty_eq_1(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nDuty ratio equation 1 selected:\n" << std::endl;
  std::cout << "K = t(on)/Ts\n" << std::endl;
  std::cout << "Please enter a value for t(on).\n" << std::endl;
  float ton = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the time period (Ts).\n" << std::endl;
  float Ts = valcheck.checkvalinput();
  K = ton/Ts;
  std::cout << "\nDuty ratio = " << K << ".\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::duty_eq_2(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nDuty ratio equation 2 selected:\n" << std::endl;
  std::cout << "K = 1-(t(off)/Ts)\n" << std::endl;
  std::cout << "Please enter a value for t(off).\n" << std::endl;
  float toff = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the time period (Ts).\n" << std::endl;
  float Ts = valcheck.checkvalinput();
  K = 1-(toff/Ts);
  std::cout << "\nDuty ratio = " << K << ".\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::duty_eq_3(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nDuty ratio equation 3 selected:\n" << std::endl;
  std::cout << "K = 1-(Vi/Vo)\n" << std::endl;
  std::cout << "Please enter a value for voltage out (Vo).\n" << std::endl;
  float Vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for voltage in (Vi).\n" << std::endl;
  float Vi = valcheck.checkvalinput();
  K = 1-(Vi/Vo);
  std::cout << "\nDuty ratio = " << K << ".\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::duty_eq_4(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nDuty ratio equation 4 selected:\n" << std::endl;
  std::cout << "K = 1-(Io/Ii)\n" << std::endl;
  std::cout << "Please enter a value for current in (Ii).\n" << std::endl;
  float Ii = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current out (Io).\n" << std::endl;
  float Io = valcheck.checkvalinput();
  K = 1-(Io/Ii);
  std::cout << "\nDuty ratio = " << K << ".\n";
  storage_check();
  go_back_to_boost();
}

//code relating to duty ratio menu ends here

void Boostmenu::boost_eq_6(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nInductor (L) selected:\n" << std::endl;
  std::cout << "L = (K x Vi)/(Fs x Δi)\n" << std::endl;
  std::cout << "Please enter a value for duty ratio (K).\n" << std::endl;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for voltage in (Vi).\n" << std::endl;
  float Vi = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for switching frequency (Fs).\n" << std::endl;
  float Fs = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current ripple magnitude (Δi).\n" << std::endl;
  float i = valcheck.checkvalinput();
  L = (K*Vi)/(Fs*i);
  std::cout << "\nInductor value = " << L << " SI.\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::boost_eq_7(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nCurrent ripple magnitude (Δi) selected:\n" << std::endl;
  std::cout << "Δi = (K x Ts x Vi)/L\n" << std::endl;
  std::cout << "Please enter a value for duty ratio (K).\n" << std::endl;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for time period (Ts).\n" << std::endl;
  float Ts = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for voltage in (Vi).\n" << std::endl;
  float Vi = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the inductor (L).\n" << std::endl;
  float L = valcheck.checkvalinput();
  i = (K*Ts*Vi)/L;
  std::cout << "\nCurrent ripple magnitude = " << i << " A.\n";
  storage_check();
  go_back_to_boost();
}

//code relating to cap menu begins here

void Boostmenu::boost_eq_8(){
  Func clr;
  clr.clear();
  print_cap_menu();
  Func check;
  int yourchoice = check.checkmenuinput(4);
  select_cap_item(yourchoice);
}

void Boostmenu::select_cap_item(int input){
  switch (input)
{ case 1: cap_eq_1(); break;
  case 2: cap_eq_2();break;
  case 3: cap_eq_3(); break;
  case 4: boost_converter();break;
  default: std::cout <<"invalid"; break;
  }
}

void Boostmenu::print_cap_menu(){
  std::cout << "\n--------- Capacitor (Co) Equation Menu ----------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Co = ΔQ/Δvo\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t2. Co = (Io x K)/(Δvo x Fs)\t\t\t\t\t|\n";
  std::cout << "|\t3. Co = (Vo x K)/(Δvo x R x Fs)\t\t\t\t|\n";
  std::cout << "|\t4. Return\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-------------------------------------------------\n";
  std::cout << "\nPlease select an equation for the capacitor.\n";
  std::cout << "\nSelect item: ";
}

void Boostmenu::cap_eq_1(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nCapacitor equation 1 selected:\n" << std::endl;
  std::cout << "Co = ΔQ/Δvo\n" << std::endl;
  std::cout << "Please enter a value for the charge on the capacitor (ΔQ).\n" << std::endl;
  float Q = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current ripple magnitude (Δvo).\n" << std::endl;
  float vo = valcheck.checkvalinput();
  Co = (Q/vo);
  std::cout << "\nCapacitor = " << Co << " F.\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::cap_eq_2(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nCapacitor equation 2 selected:\n" << std::endl;
  std::cout << "Co = (Io x K)/(Δvo x Fs)\n" << std::endl;
  std::cout << "Please enter a value for current out (Io).\n" << std::endl;
  float Io = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the duty ratio (K).\n" << std::endl;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current ripple magnitude (Δvo).\n" << std::endl;
  float vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for switching frequency (Fs).\n" << std::endl;
  float Fs = valcheck.checkvalinput();
  capacitor_calc1(K, Io, Fs, vo, Co, Q);
  std::cout << "\nCapacitor = " << Co << " F.\n";
  std::cout << "\nCharge = " << Q << " C.\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::capacitor_calc1(float K, float Io, float Fs, float vo, float &Co, float &Q){
  Co = (Io*K)/(vo*Fs);
  Q = Co*vo;
}

void Boostmenu::cap_eq_3(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nCapacitor equation 3 selected:\n" << std::endl;
  std::cout << "Co = (Vo x K)/(Δvo x R x Fs)\n" << std::endl;
  std::cout << "Please enter a value for current out (Vo).\n" << std::endl;
  float Vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the duty ratio (K).\n" << std::endl;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for current ripple magnitude (Δvo).\n" << std::endl;
  float vo = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the resistor (R).\n" << std::endl;
  float R = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for switching frequency (Fs).\n" << std::endl;
  float Fs = valcheck.checkvalinput();
  capacitor_calc2(K, Vo, Fs, vo, R, Co, Q);
  std::cout << "\nCapacitor = " << Co << " F.\n";
  std::cout << "\nCharge = " << Q << " C.\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::capacitor_calc2(float Vo, float K, float vo, float R, float Fs, float &Co, float &Q){
  Co = (Vo*K)/(vo*R*Fs);
  Q = Co*vo;
}

//code relating to cap menu ends here

//code relating to volt menu begins here

void Boostmenu::boost_eq_9(){
  Func clr;
  clr.clear();
  print_volt_menu();
  Func check;
  int yourchoice = check.checkmenuinput(3);
  select_volt_item(yourchoice);
}

void Boostmenu::select_volt_item(int input){
  switch (input)
{ case 1: voltrip_eq_1(); break;
  case 2: voltrip_eq_2();break;
  case 3: boost_converter();break;
  default: std::cout <<"invalid"; break;
  }
}

void Boostmenu::print_volt_menu(){
  std::cout << "\n- Voltage Ripple Magnitude (Δvo) Equation Menu -\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t   |\n";
  std::cout << "|\t1. Δvo = (% x Vo)/100\t\t\t\t\t   |\n";
  std::cout << "|\t2. Δvo = (K x Ts)/(R x Co)\t\t\t\t   |\n";
  std::cout << "|\t3. Return\t\t\t\t\t\t\t\t   |\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t   |\n";
  std::cout << "------------------------------------------------\n";
  std::cout << "\nPlease select an equation for the voltage ripple magnitude.\n";
  std::cout << "\nSelect item: ";
}

void Boostmenu::voltrip_eq_1(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nVoltage ripple magnitude equation 1 selected:\n" << std::endl;
  std::cout << "Δvo = (% x Vo)/100\n" << std::endl;
  std::cout << "\nPlease enter a value for the voltage ripple magnitude percentage (%).\n" << std::endl;
  float perc = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for voltage out (Vo).\n" << std::endl;
  float Vo = valcheck.checkvalinput();
  vo = (perc*Vo)/100;
  std::cout << "\nVoltage ripple magnitude = " << vo << " V.\n";
  storage_check();
  go_back_to_boost();
}

void Boostmenu::voltrip_eq_2(){
  Func clr;
  Func valcheck;
  clr.clear();
  std::cout << "\nVoltage ripple magnitude equation 2 selected:\n" << std::endl;
  std::cout << "Δvo = (K x Ts)/(R x Co)\n" << std::endl;
  std::cout << "Please enter a value for the duty ratio (K).\n" << std::endl;
  float K = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the time period (Ts).\n" << std::endl;
  float Ts = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the resistor (R).\n" << std::endl;
  float R = valcheck.checkvalinput();
  std::cout << "\nPlease enter a value for the capacitor (Co).\n" << std::endl;
  float Co = valcheck.checkvalinput();
  vo = (K*Ts)/(R*Co);
  std::cout << "\nVoltage ripple magnitude = " << vo << " V.\n";
  storage_check();
  go_back_to_boost();
}

//code relating to volt menu ends here

void Boostmenu::storage_check(){
do {
  std::cout<<"\nDo you want to store the values of this calculation?\n";
    std::cout << "\nEnter 'y' for yes or 'n' for no: ";
    std::cin >> input5;
  } while (input5 != "y" && input5 != "n");
  if (input5 == "y") {
    switch_array1[I] = Fs;
    time_array1[I] = Ts; 
    duty_array1[I] = K;
    pin_array1[I] = Pin;
    pout_array1[I] = Pout;
    inductor_array1[I] = L;
    currip_array1[I] = i;
    cap_array1[I] = Co;
    charge_array1[I] = Q;
    volrip_array1[I] = vo;
    Fs=0;
    Ts=0;
    K=0;
    L=0;
    i=0;
    Co=0;
    Q=0;
    vo=0;
    I=I+1;
    if(I>10){I=0;}
    go_back_to_boost();
  }
  else{
   go_back_to_boost();
  }
} 


void Boostmenu::calc_hist(){
  Func check;
  std::cout<<"\nEnter the number of the calculation you want to view";
  std::cout << "\ni.e. for the 1st calculation enter 1: ";
input = check.checkcalcinput();
  if(input>10||input<1) {std::cout<<"The maximum stored values are 10, please eneter an integer between 1 and 10";
   calc_hist();
    }
  float *ptr1 = &switch_array1[input-1];
  float *ptr2 = &time_array1[input-1];
  float *ptr3 = &pin_array1[input-1];
  float *ptr4 = &pout_array1[input-1];
  float *ptr5 = &duty_array1[input-1];
  float *ptr6 = &inductor_array1[input-1];
  float *ptr7 = &currip_array1[input-1];
  float *ptr8 = &cap_array1[input-1];
  float *ptr9 = &charge_array1[input-1];
  float *ptr10 = &volrip_array1[input-1];
std::cout<<"\nCalculation "<<input<<":\n";
  std::cout<<"\n Switching Frequency = " << *ptr1 << " s.";
  std::cout<<"\n Time period = " << *ptr2 << " s.";
  std::cout<<"\n Power in = " << *ptr3 << " W.";
  std::cout<<"\n Power out = " << *ptr4 << " W.";
  std::cout<<"\n Duty Ratio = " << *ptr5 << ".";
  std::cout<<"\n Inductor = " << *ptr6 << " SI.";
  std::cout<<"\n Current ripple magnitude = " << *ptr7 << " A.";
  std::cout<<"\n Capacitor = " << *ptr8 << " C.";
  std::cout<<"\n Charge = " << *ptr9 << " F.";
  std::cout<<"\n Voltage ripple magnitude = " << *ptr10 << " V.\n"; 
  go_back_to_boost();
}

void Boostmenu::go_back_to_boost() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to buck menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  Func clr;
  clr.clear();
  boost_converter();
}