#include <iostream>
#include <string>

using namespace std;

class CryptoExceptions {

public:
   CryptoExceptions(const string& msg) : msg_(msg) {}
  ~CryptoExceptions() {}

   string what() const {return(msg_);}
private:
   string msg_;
};
