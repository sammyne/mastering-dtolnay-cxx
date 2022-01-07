#pragma once

#include <memory>

#include "rust/cxx.h"


namespace demo {

using hello_fn = rust::Fn<void(const rust::Vec<uint32_t>&)>;
  
class Testbot {
  public:
    void say_hello_world(hello_fn) const;
};

std::unique_ptr<Testbot> new_testbot();

}