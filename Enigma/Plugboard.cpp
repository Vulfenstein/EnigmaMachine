#include "Plugboard.h"
#include <iostream>
using namespace std;

//----------------------------------------------------------------------------//
//CTOR
//----------------------------------------------------------------------------//
Plugboard::Plugboard()
{
  //initialize plugboard
  for(int i = 0; i < 26; i++){
    plugs[i][0] = i;
    plugs[i][1] = i;
  }
}

//----------------------------------------------------------------------------//
//DTOR
//----------------------------------------------------------------------------//
Plugboard::~Plugboard()
{
}

//----------------------------------------------------------------------------//
//RUNTHROUGH
//----------------------------------------------------------------------------//
int Plugboard::runThrough(int input)
{
  //return character corresponding to input character
  return plugs[input][1];
}

//----------------------------------------------------------------------------//
//PRINT
//----------------------------------------------------------------------------//
void Plugboard::print()
{
  //print value of plugboard array
  for(int i = 0; i < 26; i++){
    cout << plugs[i][0] << " " << plugs[i][1] << endl;
  }
}

//----------------------------------------------------------------------------//
//CHANGEINPUTS
//----------------------------------------------------------------------------//
void Plugboard::changeInputs(int first, int second)
{
  //swap character values
  plugs[first][1] = second;
  plugs[second][1] = first;
}
