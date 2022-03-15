#pragma once

#include <memory>
#include <string>

namespace demo
{

  class Testbot
  {
  public:
    std::unique_ptr<std::string> hello_world() const;
  };

  std::unique_ptr<Testbot> new_testbot();

}