#include "call-cc-with-separated-extern-block/include/hello-world2.h"

#include <iostream>

namespace demo {

using std::cout;
using std::endl;

void Testbot2::say_hello_world() const {
  cout << "hello world2"<<endl;
}

std::unique_ptr<Testbot2> new_testbot2() {
  return std::make_unique<Testbot2>();
}

}
