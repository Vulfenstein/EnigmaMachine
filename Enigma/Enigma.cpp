#include "Enigma.h"
#include <iostream>
using namespace std;

//----------------------------------------------------------------------------//
//CTOR
//----------------------------------------------------------------------------//
Enigma::Enigma()
{
}

//----------------------------------------------------------------------------//
//DTOR
//----------------------------------------------------------------------------//
Enigma::~Enigma()
{
}

//----------------------------------------------------------------------------//
//SET ROTORS
//----------------------------------------------------------------------------//
void Enigma::setRotors(int first, int second, int third)
{
  rot1 = Rotor(first, 1);
  rot2 = Rotor(second, 2);
  rot3 = Rotor(third, 3);
}

//----------------------------------------------------------------------------//
//SET POSITIONS
//----------------------------------------------------------------------------//
void Enigma::setRotorPositions(int first, int second, int third)
{
  rot1.setPosition(first);
  rot2.setPosition(second);
  rot3.setPosition(third);
}

//----------------------------------------------------------------------------//
//UPDATE ROTOR POSITIONS
//----------------------------------------------------------------------------//
void Enigma::updateRotorPositons()
{
  int reset = 0;
  // rotor1 is always increased, if rotor1 == 25 it's reset to 0
  // and rotor2 is incremented. same is true for rotor3 if rotor2 == 25
  rot1.setPosition(rot1.getPosition() + 1);
  if(rot1.getPosition() == 25){
    rot1.setPosition(reset);
    rot2.setPosition(rot2.getPosition() + 1);
    if(rot2.getPosition() == 25){
      rot2.setPosition(reset);
      rot3.setPosition(rot3.getPosition() + 1);
      if(rot3.getPosition() == 25){
        rot3.setPosition(reset);
      }
    }
  }
}

//----------------------------------------------------------------------------//
//RUN MACHINE
//----------------------------------------------------------------------------//
char Enigma::runMachine(char input)
{
  //original alphabet used for returning character at end
  string originalletters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  //convert input into integer equivalent
  int inputNo = convert(input);

  //run through plugboard, rotors 1,2,3, reflector, 3,2,1, plugboard.
  int currentNo = inputNo;
  currentNo = plugboard.runThrough(currentNo);
  currentNo = rot1.runThrough(currentNo, true);
  currentNo = rot2.runThrough(currentNo, true);
  currentNo = rot3.runThrough(currentNo, true);
  currentNo = reflect.runThrough(currentNo, true);
  currentNo = rot3.runThrough(currentNo, false);
  currentNo = rot2.runThrough(currentNo, false);
  currentNo = rot1.runThrough(currentNo, false);
  currentNo = plugboard.runThrough(currentNo);
  //'turn' rotors
  updateRotorPositons();

  //currentNo equals number 0-25. return char found at that position in alphabet
  return originalletters[currentNo];
}

//----------------------------------------------------------------------------//
//UPDATEPLUGS
//----------------------------------------------------------------------------//
void Enigma::updatePlugs(char first, char second)
{
  //convert to integers and swap values in plugboard
  int fir, sec;
  fir = convert(first);
  sec = convert(second);
  plugboard.changeInputs(fir, sec);
}

//----------------------------------------------------------------------------//
//CONVERT
//----------------------------------------------------------------------------//
int Enigma::convert(char input)
{
  //simple converter for character to integer equivalent
  switch(input){
    case 'a':
    case 'A':
      return 0;
    case 'b':
    case 'B':
      return 1;
    case 'c':
    case 'C':
      return 2;
    case 'd':
    case 'D':
      return 3;
    case 'e':
    case 'E':
      return 4;
    case 'f':
    case 'F':
      return 5;
    case 'g':
    case 'G':
      return 6;
    case 'h':
    case 'H':
      return 7;
    case 'i':
    case 'I':
      return 8;
    case 'j':
    case 'J':
      return 9;
    case 'k':
    case 'K':
      return 10;
    case 'l':
    case 'L':
      return 11;
    case 'm':
    case 'M':
      return 12;
    case 'n':
    case 'N':
      return 13;
    case 'o':
    case 'O':
      return 14;
    case 'p':
    case 'P':
      return 15;
    case 'q':
    case 'Q':
      return 16;
    case 'r':
    case 'R':
      return 17;
    case 's':
    case 'S':
      return 18;
    case 't':
    case 'T':
      return 19;
    case 'u':
    case 'U':
      return 20;
    case 'v':
    case 'V':
      return 21;
    case 'w':
    case 'W':
      return 22;
    case 'x':
    case 'X':
      return 23;
    case 'y':
    case 'Y':
      return 24;
    case 'z':
    case 'Z':
      return 25;
    default:
      return 1;
  }
}
