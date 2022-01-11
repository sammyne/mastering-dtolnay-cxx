#include "hello-world/include/hello-world.h"

#include <iostream>

namespace demo {

using std::cout;
using std::endl;

void say_hello(const string& who) {
  cout << "hello "<< who << endl;
}

}
