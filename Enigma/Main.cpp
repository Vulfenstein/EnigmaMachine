#include <iostream>
#include <fstream>
#include "Enigma.h"
#include "Plugboard.h"
using namespace std;

int rotorMAX = 5;
int positionMAX = 26;
void AssignValues(int& rotor, int& startposition, string name);
int errorHandle(char user_input, int value);

//----------------------------------------------------------------------------//
//MAIN
//----------------------------------------------------------------------------//
int main(){
char first_char;
char second_char;
int rotor_1;
int rotor_2;
int rotor_3;
int plugcount = 0;
int rotor1_position;
int rotor2_position;
int rotor3_position;
vector<char> message;
ofstream myfile ("message.txt");

Enigma Machine;
AssignValues(rotor_1, rotor1_position, "first");
AssignValues(rotor_2, rotor2_position, "second");
AssignValues(rotor_3, rotor3_position, "third");

//write to file
myfile << "Rotors and positions:\n";
myfile << rotor_1 << " " << rotor1_position << endl;
myfile << rotor_2 << " " << rotor2_position << endl;
myfile << rotor_3 << " " << rotor3_position << endl;
myfile << "\nPlugboard connection:\n";

//Plugboard
cout << "\nEnter plugboard values(A-Z A-Z)\n";
cout << "Enter '+' to exit plugboard setup.\n";
while(plugcount < 20){
  cout << "Plugs: ";
  cin >> first_char;
  if(first_char == '+')
    break;
  cin >> second_char;
  Machine.updatePlugs(first_char, second_char);
  plugcount++;
  myfile << first_char << " " << second_char << endl;
}

//declare rotors, and set positions
cout << "\nWrite Message. Press enter. Press '+' to exit\n";
Machine.setRotors(rotor_1, rotor_2, rotor_3);
Machine.setRotorPositions(rotor1_position, rotor2_position, rotor3_position);

//while user is entering characters
while(cin>>first_char){
  if(first_char == '+')
    break;
  if(first_char == ' ')
    continue;
  second_char = Machine.runMachine(first_char);
  message.push_back(second_char);
  cout << first_char << " = " << second_char << endl;
 }

myfile << "\n";
for(int i = 0; i < (int)message.size(); i++){
   myfile << message[i] << " ";
}

cout << endl;
return 0;
}

//----------------------------------------------------------------------------//
//ASSIGN VALUES
//----------------------------------------------------------------------------//
void AssignValues(int& rotor, int& startposition, string name)
{
  cout << "Select " << name << " rotor(1-5): ";
  cin >> rotor;
  if(rotor > rotorMAX || rotor <= 0)
    rotor = errorHandle(rotor, rotorMAX);
  cout << "Select starting position(1-26): ";
  cin >> startposition;
  if(startposition > positionMAX || startposition <= 0)
    startposition = errorHandle(startposition, positionMAX);
}

//----------------------------------------------------------------------------//
//ERROR HANDLE
//----------------------------------------------------------------------------//
int errorHandle(char user_input, int value)
{
  int input;
  input = user_input;
  while(input > value){
    cout << "Error: enter a number from 1-" << value << endl;
    cin >> input;
  }
  return input;
}
