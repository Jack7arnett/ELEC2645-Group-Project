#include "opamp.h"
#include "generalfunctions.h"

void Opamp::op_amp_menu() {
  Func clr;
  clr.clear();
  std::cout << "\n---------------op amp calculator--------------\n";
	std::cout << "|\t                                           |\n";
	std::cout << "|\t1. Inverting op amp                        |\n";
	std::cout << "|\t2. Non-inverting op amp                    |\n";
	std::cout << "|\t3. Summing amplifier                       |\n";
  std::cout << "|\t4. History for inverting & non inverting   |\n";  
  std::cout << "|\t5. Return to main menu                     |\n";
	std::cout << "|\t                                           |\n";
	std::cout << "------------------------------------------------\n";
  std::cout<<"Select item: ";
  Func check;
  int option = check.checkmenuinput(5);
  if (option == 1){
  Func valcheck;
  std::cout<<"Please Enter: \n";
  std::cout<<"Vin in V: ";
  Vin = valcheck.checkvalinput();
  std::cout<<"\nRin in ohms: ";
  Rin = valcheck.checkvalinput();
  std::cout<<"\nRf in ohms: ";
  Rf = valcheck.checkvalinput();
  inverting inverting;
  float A = inverting.get_gain(Rf, Rin);
  clr.clear();
  std::cout<<"\nThe gain for this inverting amplifier is -"<< A << ", - sign means the output signal is 180 degrees out of phase with the input\n";
  float Vout = inverting.get_vout(A, Vin);
    std::cout<<"\nThe voltage output for this inverting amplifier is "<<Vout<< "V";
  float fmax = inverting.get_fmax(Vout);
    std::cout<<"\nThe maximum operating frequency for this inverting amplifier is "<<fmax<< "Hz\n";
    do {
  std::cout<<"\nDo you want to store the values of this calculations? ";
    std::cout << "\nEnter 'y' for yes or 'n' for no : ";
    std::cin >> input;
  } while (input != "y" && input != "n");
  if (input == "y") {
    voltageinput[i]= Vin;
    voltageresult[i]= Vout;
    gainresult[i]= A;
    frequencyresult[i]= fmax;
    resistorin_array[i]= Rin;
    resistorf_array [i]= Rf; 
 Vin=0;
 Vout=0;
 A=0;
 fmax=0;
 Rin =0;
 Rf=0;
    i=i+1;
    if(i>10){i=0;}
  go_back_to_opamp();
  }
  else{
  go_back_to_opamp();
  }
  }
  
  if(option == 2){
  Func valcheck;
  std::cout<<"Please Enter: \n";
  std::cout<<"Vin in V: ";
  Vin = valcheck.checkvalinput();
  std::cout<<"\nRin in ohms: ";
  Rin = valcheck.checkvalinput();
  std::cout<<"\nRf in ohms: ";
  Rf = valcheck.checkvalinput();
  noninverting noninverting;
  float A = noninverting.get_gain(Rf, Rin);
  clr.clear();    
  std::cout<<"\nThe gain for this non-inverting amplifier is "<< A << std::endl;
  float Vout = noninverting.get_vout(A, Vin);
    std::cout<<"\nThe voltage output for this non-inverting amplifier is "<<Vout<< "V";
  float fmax = noninverting.get_fmax(Vout);
    std::cout<<"\nThe maximum operating frequency for this non-inverting amplifier is "<<fmax<< "Hz\n";
    
    do {
  std::cout<<"\nDo you want to store the values of this calculations? ";
    std::cout << "\nEnter 'y' for yes or 'n' for no : ";
    std::cin >> input;
  } while (input != "y" && input != "n");
  if (input == "y") {
    voltageinput[i]= Vin;
    voltageresult[i]= Vout;
    gainresult[i]= A;
    frequencyresult[i]= fmax;
    resistorin_array[i]= Rin;
    resistorf_array [i]= Rf; 
 Vin=0;
 Vout=0;
 A=0;
 fmax=0;
 Rin =0;
 Rf=0;
    i=i+1;
    if(i>10){i=0;}
  go_back_to_opamp();
  }
  else{
  go_back_to_opamp();
  }
  }
  
  if(option == 3){
    Func valcheck;
    std::cout << "Please input number of inputs signals: ";
  n = valcheck.checkvalinput();
  std::cout << "Please input the values for resistors respectively: ";
  int resistors [n];
  for (int i=0; i<n; i++){
    resistors[i] = valcheck.checkvalinput();
  }
  std::cout << "Please input the values for voltage inputs respectively: ";
  int voltages [n];
  for (int i=0; i<n; i++){
    voltages[i] = valcheck.checkvalinput();
  }
    int sum = 0;
    for (int i = 0; i < n; i++) {
    sum += (voltages[i] / resistors[i]);
  }
  std::cout << "Please input the value for feedback resistor Rf: ";
  Rf = valcheck.checkvalinput();
  Vout = -Rf * sum;
  clr.clear();  
  std::cout << "The output voltage for this summing amplifier is "<< Vout <<" V";
  }

if(option == 4){
  history();
}
  
  if(option == 5){
    Mainmenu main;
    main.main_menu();
  }
}


void Opamp::history(){
  std::cout<<"\n Choose the order of the calculation you want to view ";
  Func valcheck;
input2=valcheck.checkvalinput();
  if(input2>10||input2<1) {std::cout<<"the maximum stored values are 10, please enter an integer between 1 and 10";
   history();
    }
  double *ptrvi = &voltageinput[input2-1];
  double *ptrvo = &voltageresult[input2-1];
  double *ptra= &gainresult[input2-1];
  double *ptrf=&frequencyresult[input2-1];
  double *ptrrin=&resistorin_array[input2-1];
  double *ptrrf=&resistorf_array[input2-1];
std::cout<<"The calculation order "<<input2<<" is: ";
  std::cout<<"\n input voltage : "<<*ptrvi;
  std::cout<<"\n output voltage : "<<*ptrvo;
  std::cout<<"\n gain : "<<*ptra;
  std::cout<<"\n maximum frequency : "<<*ptrf;
  std::cout<<"\n input resistor : "<<*ptrrin;
  std::cout<<"\n feedback resistor : "<<*ptrrf;
  go_back_to_opamp();
}

void Opamp::go_back_to_opamp() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to op amp menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  Func func;
  func.clear();
  op_amp_menu();
}
  