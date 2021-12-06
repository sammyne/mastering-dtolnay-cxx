#pragma once

#include <memory>

#include "rust/cxx.h"

namespace demo {
  
class Testbot {
  public:
    Testbot();
    ~Testbot();

    void say_hello_world() const;

  public:
    struct data;
    data *data_;
};

std::unique_ptr<Testbot> new_testbot();

}