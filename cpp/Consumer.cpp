#include "Style.h"

#include <iostream>
#include <cassert>

// This is implemented in Rust.
extern "C" Style* ComputeStyle();
extern "C" void FreeStyle(Style*);

static const char* FloatToString(StyleFloat aFloat)
{
  switch (aFloat) {
    case StyleFloat::Left:
      return "left";
    case StyleFloat::Right:
      return "right";
    case StyleFloat::None:
      return "none";
  }
  assert(false);
  return "Whoops, someone messed up";
}

extern "C" int main_cpp()
{
  auto* style = ComputeStyle();
  std::cout << "Got a color: " << style->m_color->m_color << std::endl;
  std::cout << "Got a float: " << FloatToString(style->m_display->m_float) << std::endl;
  FreeStyle(style);
  return 0;
}
