#include<iostream>
#include "Rotors.h"
using namespace std;

//----------------------------------------------------------------------------//
//CTOR
//----------------------------------------------------------------------------//
Rotor::Rotor()
{
}

//----------------------------------------------------------------------------//
//DTOR
//----------------------------------------------------------------------------//
Rotor::~Rotor()
{
}

//----------------------------------------------------------------------------//
//CTOR
//----------------------------------------------------------------------------//
Rotor::Rotor(int rotorNumber, int rotorPosition)
  : rotorNo(rotorNumber), rotorPos(rotorPosition)
{
  //depending on results of rotorNumber assign the appropriate encryption
  if(rotorNumber == 1){
    int temp[] = {15, 4, 25, 20, 14, 7, 23, 18, 2, 21, 5, 12, 19, 1, 6, 11, 17, 8, 13, 16, 9, 22, 0, 24, 3, 10};
    for(int i = 0; i < 26; i++){
      wiring[i][0] = i;
      wiring[i][1] = temp[i];
    }
    return;
  }
  else if(rotorNumber == 2){
    int temp[] = {25, 14, 20, 4, 18, 24, 3, 10, 5, 22, 15, 2, 8, 16, 23, 7, 12, 21, 1, 11, 6, 13, 9, 17, 0, 19};
    for(int i = 0; i < 26; i++){
      wiring[i][0] = i;
      wiring[i][1] = temp[i];
    }
    return;
  }
  else if(rotorNumber == 3){
    int temp[] = {4, 7, 17, 21, 23, 6, 0, 14, 1, 16, 20, 18, 8, 12, 25, 5, 11, 24, 13, 22, 10, 19, 15, 3, 9, 2};
    for(int i = 0; i < 26; i++){
      wiring[i][0] = i;
      wiring[i][1] = temp[i];
    }
    return;
  }
  else if(rotorNumber == 4){
    int temp[] = {8, 12, 4, 19, 2, 6, 5, 17, 0, 24, 18, 16, 1, 25, 23, 22, 11, 7, 10, 3, 21, 20, 15, 14, 9, 13};
    for(int i = 0; i < 26; i++){
      wiring[i][0] = i;
      wiring[i][1] = temp[i];
    }
    return;
  }
  else if(rotorNumber == 5){
    int temp [] = {16, 22, 4, 17, 19, 25, 20, 8, 14, 0, 18, 3, 5, 6, 7, 9, 10, 15, 24, 23, 2, 21, 1, 13, 12, 11};
    for(int i = 0; i < 26; i++){
      wiring[i][0] = i;
      wiring[i][1] = temp[i];
    }
    return;
  }
}

//----------------------------------------------------------------------------//
//RUN ROTOR
//----------------------------------------------------------------------------//
int Rotor::runThrough(int input, bool forward)
{
  //if going forward simply return input
  if (forward) {
    input = (input+rotorPos) % 26;
    return wiring[input][1];
  }
  //heading back through rotors
  else {
    //find reverse of input value (0-25)
    for (int i = 0; i < 26; i++) {
      if (input == wiring[i][1]) {
        int output = (wiring[i][0]-rotorPos);
        while (output<0) {
          output = 26+output;
        }
        output = output % 26;
        return output;
      }
    }
  }
  return 0;
}

//----------------------------------------------------------------------------//
//GET POSITION
//----------------------------------------------------------------------------//
int Rotor::getPosition()
{
  return rotorPos;
}

//----------------------------------------------------------------------------//
//SET POSITION
//----------------------------------------------------------------------------//
void Rotor::setPosition(int pos)
{
  rotorPos = pos;
  return;
}

//----------------------------------------------------------------------------//
//PRINT
//----------------------------------------------------------------------------//
void Rotor::printRotor()
{
  for(int i = 0; i < 26; i++){
      cout << wiring[i][1] << " ";
  }
  cout << endl;
}
