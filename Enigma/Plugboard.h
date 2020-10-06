#ifndef PLUGBOARD_H
#define PLUGBOARD_H

class Plugboard {
  public:
    Plugboard();
    ~Plugboard();
    int runThrough(int input);
    void print();
    void changeInputs(int first, int second);
  private:
    int plugs[26][2];
};
#endif
