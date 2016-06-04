#ifndef _IRUNN_HH
#define _IRUNN_HH

// #include <stdio.h>
// #include <iostream>
// #include <fstream>
#include <string>
using namespace std;
template <class typ1,class typ2>
class irunnable{
public:
  
  virtual bool prepare(int,typ1,typ2)=0;
  virtual int run(typ1)=0;
  
  virtual void remove()=0;
};



#endif
