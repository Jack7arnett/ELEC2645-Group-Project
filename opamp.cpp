#include "opamp.h"
#include "generalfunctions.h"

void Opamp::op_amp_menu() {
  Func clr;
  clr.clear();
  std::cout << "\n--------op amp calculator--------\n";
	std::cout << "|\t                             |\n";
	std::cout << "|\t1. Inverting op amp          |\n";
	std::cout << "|\t2. Non-inverting op amp      |\n";
	std::cout << "|\t3. Summing amplifier         |\n";
	std::cout << "|\t                             |\n";
	std::cout << "---------------------------------\n";
  std::cout<<"Select item: ";
  Func check;
  int option = check.checkmenuinput(3);
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
}

  