#pragma once

#include <memory>
#include <string>

#include "rust/cxx.h"

namespace demo {

using hello_fn = rust::Fn<void(const rust::Vec<uint32_t>&)>;
using world_fn = auto (*)(const std::string &s) -> void;
using world2_fn = rust::Fn<void(const std::string&)>;
  
class Testbot {
  public:
    void say_hello_world(hello_fn) const;
    void hi(world2_fn) const;
};

std::unique_ptr<Testbot> new_testbot();

}