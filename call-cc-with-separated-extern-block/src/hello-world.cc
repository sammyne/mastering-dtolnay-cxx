#include "call-cc-with-separated-extern-block/include/hello-world.h"

#include <iostream>

namespace demo {

using std::cout;
using std::endl;

void Testbot::say_hello_world() const {
  cout << "hello world"<<endl;
}

std::unique_ptr<Testbot> new_testbot() {
  return std::make_unique<Testbot>();
}

}
