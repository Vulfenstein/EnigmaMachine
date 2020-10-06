#ifndef ROTORS_H
#define ROTORS_H
#include <vector>

class Rotor{
  public:
    Rotor();
    ~Rotor();
    Rotor(int rotorNumber, int rotorPosition);
    void printRotor();
    void setPosition(int pos);
    void assignRotorNumbers(int rotorNumber);
    int getPosition();
    int runThrough(int input, bool forward);
  private:
    int wiring[26][2];
    int rotorPos;
    int rotorNo;
};
#endif
