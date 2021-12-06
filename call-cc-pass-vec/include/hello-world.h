#pragma once

#include <memory>
#include <vector>

#include "rust/cxx.h"

namespace demo {
  
class Testbot {
  public:
    rust::Vec<uint32_t> increment(const rust::Vec<uint32_t> &v) const;  

    void say_hello_world() const;
};

std::unique_ptr<Testbot> new_testbot();

}