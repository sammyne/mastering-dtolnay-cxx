#include "call-cc-with-passed-fn/include/hello-world.h"

#include <iostream>

namespace demo {

using std::cout;
using std::endl;

void Testbot::say_hello_world(hello_fn hello) const {
  rust::Vec<uint32_t> v{1,2,3};
  hello(v);
  cout << "hello world"<<endl;
}

std::unique_ptr<Testbot> new_testbot() {
  return std::make_unique<Testbot>();
}

}
