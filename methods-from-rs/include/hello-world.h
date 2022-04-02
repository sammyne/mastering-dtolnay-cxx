#pragma once

#include <memory>
#include <string>

namespace demo {

class HelloWorld {
 public:
  HelloWorld();
  ~HelloWorld();

  void hello_world() const;

 public:
  class Impl;
  std::unique_ptr<Impl> impl_;
};

std::unique_ptr<HelloWorld> new_hello_world();

}  // namespace demo