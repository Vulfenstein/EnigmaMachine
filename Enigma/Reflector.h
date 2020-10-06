#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector {
public:
  Reflector();
  ~Reflector();
  int runThrough(int input, bool forward);
  int wirings[26][2];
};
#endif
