#include "hello-world/include/hello-world.h"

#include <iostream>

namespace demo
{

  using std::string;
  using std::unique_ptr;

  unique_ptr<string> Testbot::hello_world() const
  {
    return std::make_unique<string>("hello world :)");
  }

  std::unique_ptr<Testbot> new_testbot()
  {
    return std::make_unique<Testbot>();
  }

}
