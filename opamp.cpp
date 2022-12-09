#include "opamp.h"

void Opamp::op_amp_menu() {
  std::cout << "\n---------------------------------\n";
	std::cout << "|\t                             |\n";
	std::cout << "|\t1. Inverting op amp          |\n";
	std::cout << "|\t2. Non-inverting op amp      |\n";
	std::cout << "|\t3. Summing amplifier         |\n";
	std::cout << "|\t                             |\n";
	std::cout << "---------------------------------\n";
  std::cout<<"Select item: ";
  //  https://www.youtube.com/watch?v=YIX7UhIKEIk
  while(!(std::cin>> option)){ //this makes sure the input is integer only
  std::cout<<"\nPlease choose: 1) Inverting op amp 2) non-inverting op amp 3) Summing amplifier\n";
  std::cin.clear();
  std::cin.ignore(100, '\n');
  }
  if (option == 1){
  std::cout<<"Please Enter: \n";
  std::cout<<"Vin in V: ";
  std::cin>> Vin;
  std::cout<<"\nRin in ohms: ";
  std::cin>> Rin;
  std::cout<<"\nRf in ohms: ";
  std::cin>> Rf;
  inverting inverting;
  float A = inverting.get_gain(Rf, Rin);
  std::cout<<"\nThe gain fot this inverting amplifier is -"<< A << ", - sign means the output signal is 180 degrees out of phase with the input\n";
  float Vout = inverting.get_vout(A, Vin);
    std::cout<<"\nThe voltage output for this inverting amplifier is "<<Vout<< "V";
  float fmax = inverting.get_fmax(Vout);
    std::cout<<"\nThe maximum operating frequency for this inverting amplifier is "<<fmax<< "Hz\n";
    exit(1);
  }
  if(option == 2){
  std::cout<<"Please Enter: \n";
  std::cout<<"Vin in V: ";
  std::cin>> Vin;
  std::cout<<"\nRin in ohms: ";
  std::cin>> Rin;
  std::cout<<"\nRf in ohms: ";
  std::cin>> Rf;
  noninverting noninverting;
  float A = noninverting.get_gain(Rf, Rin);
  std::cout<<"\nThe gain fot this non-inverting amplifier is "<< A << std::endl;
  float Vout = noninverting.get_vout(A, Vin);
    std::cout<<"\nThe voltage output for this non-inverting amplifier is "<<Vout<< "V";
  float fmax = noninverting.get_fmax(Vout);
    std::cout<<"\nThe maximum operating frequency for this non-inverting amplifier is "<<fmax<< "Hz\n";
    exit(1);
  }
  if(option == 3){
    std::cout << "Please input number of inputs signals: ";
  std::cin >> n;
  std::cout << "Please input the values for resistors respectively: ";
  int resistors [n];
  for (int i=0; i<n; i++){
    std::cin >> resistors[i];
  }
  std::cout << "Please input the values for voltage inputs respectively: ";
  int voltages [n];
  for (int i=0; i<n; i++){
    std::cin >> voltages[i];
  }
    int sum = 0;
    for (int i = 0; i < n; i++) {
    sum += (voltages[i] / resistors[i]);
  }
  std::cout << "Please input the value for feedback resistor Rf: ";
  std::cin >> Rf;
  Vout = -Rf * sum;
  std::cout << "The output voltage for this summing amplifier is "<< Vout <<" V";
    exit(1);
  }
  if(option != 1 || option !=2 || option !=3){ //if a different value for option is chosen the function is recalled
    op_amp_menu();
  } 
}