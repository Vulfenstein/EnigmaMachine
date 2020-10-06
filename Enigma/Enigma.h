#ifndef ENIGMA_H
#define ENIGMA_H
#include "Rotors.h"
#include "Reflector.h"
#include "Plugboard.h"

class Enigma {
  public:
    Enigma();
    ~Enigma();
    int convert(char input);
    void updateRotorPositons();
    void setRotors(int first, int second, int third);
    void setRotorPositions(int first, int second, int third);
    void updatePlugs(char first, char second);
    char runMachine(char input);
  private:
    Rotor rot1;
    Rotor rot2;
    Rotor rot3;
    Reflector reflect;
    Plugboard plugboard;
};
#endif
