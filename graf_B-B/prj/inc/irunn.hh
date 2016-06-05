#ifndef _IRUNN_HH
#define _IRUNN_HH

class irunable{
public:
  virtual bool prepare()=0;

  virtual bool run()=0;
  
  virtual void remove()=0;
};




#endif
