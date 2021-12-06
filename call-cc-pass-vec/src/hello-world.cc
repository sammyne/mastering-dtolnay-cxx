#include "call-cc-pass-vec/include/hello-world.h"

#include <iostream>

namespace demo {

using std::cout;
using std::endl;
using std::vector;

rust::Vec<uint32_t> Testbot::increment(const rust::Vec<uint32_t> &v) const {
  rust::Vec<uint32_t> out;
  for(const auto w: v) {
    out.push_back(w+1);
  }

  return out;
}

void Testbot::say_hello_world() const {
  cout << "hello world"<<endl;
}

std::unique_ptr<Testbot> new_testbot() {
  return std::make_unique<Testbot>();
}

}
