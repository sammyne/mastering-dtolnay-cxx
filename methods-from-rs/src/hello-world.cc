#include "hello-world/include/hello-world.h"

#include <iostream>

#include "hello-world/src/main.rs.h"
#include "rust/cxx.h"

namespace demo {

using namespace std;

class HelloWorld::Impl {
 public:
  Impl() { this->hi = new_hi().into_raw(); }
  ~Impl() {
    if (nullptr == this->hi) {
      return;
    }

    rust::Box<Hi>::from_raw(this->hi);
    this->hi = nullptr;
  }

 public:
  Hi *hi;
};

HelloWorld::HelloWorld() { this->impl_ = std::make_unique<HelloWorld::Impl>(); }

HelloWorld::~HelloWorld() {}

void HelloWorld::hello_world() const {
  cout << "hello world in C++" << endl;
  this->impl_->hi->hi();
}

std::unique_ptr<HelloWorld> new_hello_world() {
  return std::make_unique<HelloWorld>();
}

}  // namespace demo
