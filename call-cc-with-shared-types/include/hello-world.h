#pragma once

#include <memory>

#include "rust/cxx.h"

namespace demo {

struct Args;
  
class Testbot {
  public:
    void say_hello_world(const Args &args) const;
};

std::unique_ptr<Testbot> new_testbot();

}