#include "hello-world/include/hello-world.h"
#include "hello-world/src/main.rs.h"

#include <iostream>

namespace demo {

using std::cout;
using std::endl;

void HelloWorld::greet(const char *who) const {
  cout << "who = " << who << endl;
}

void play() {
  HelloWorld h;

  hi(h);
}

}