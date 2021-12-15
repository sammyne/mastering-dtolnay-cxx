#include "call-cc-with-shared-types/include/hello-world.h"
#include "call-cc-with-shared-types/src/main.rs.h"

#include <iostream>
#include <string>

namespace demo {

using std::cout;
using std::endl;

void Testbot::say_hello_world(const Args &args) const {
  auto who = std::string(args.who.begin(),args.who.end());
  cout << "hello world to "<< who << endl;
}

std::unique_ptr<Testbot> new_testbot() {
  return std::make_unique<Testbot>();
}

}
