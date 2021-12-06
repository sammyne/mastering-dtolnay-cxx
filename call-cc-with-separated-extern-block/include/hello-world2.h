#pragma once

#include <memory>

#include "rust/cxx.h"

namespace demo {
  
class Testbot2 {
  public:
    void say_hello_world() const;
};

std::unique_ptr<Testbot2> new_testbot2();

}