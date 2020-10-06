#include "Reflector.h"
#include<iostream>

//----------------------------------------------------------------------------//
//CTOR
//----------------------------------------------------------------------------//
Reflector::Reflector()
{
  int temp [] = {21, 10, 22, 17, 6, 8, 4, 19, 5, 25, 1, 20, 18, 15, 16, 13, 14, 3, 12, 7, 11, 0, 2, 24, 23, 9};
  for(int i = 0; i < 26; i++){
    wirings[i][0] = i;
    wirings[i][1] = temp[i];
  }
  return;
}

//----------------------------------------------------------------------------//
//DTOR
//----------------------------------------------------------------------------//
Reflector::~Reflector()
{
}

//----------------------------------------------------------------------------//
//REFECTOR RUN
//----------------------------------------------------------------------------//
int Reflector::runThrough(int input, bool forward)
{
  input = (input) % 26;
  if (forward) {
    return wirings[input][1];
  } else {
    return wirings[input][0];
  }
}