#include "call-cc-forward-declaration/include/hello-world.h"

#include <iostream>

namespace demo {

using std::cout;
using std::endl;

struct Testbot::data {
  int v;
};

Testbot::Testbot(): data_(new(Testbot::data)) {
  cout << "constructor is called" << endl;
}

Testbot::~Testbot() {
  cout << "this is invoked"<<endl;
  if(nullptr != this->data_) {
    delete this->data_;
    this->data_ = nullptr;
  }
}

void Testbot::say_hello_world() const {
  cout << "hello world: "<< this->data_->v <<endl;
  cout << "hello world"<<endl;
}

std::unique_ptr<Testbot> new_testbot() {
  //auto data = new(Testbot::data);
  //data->v = 123;

  auto out= std::make_unique<Testbot>();
  //out->data_ = data;
  out->data_->v = 123;

  return out;
}

}
