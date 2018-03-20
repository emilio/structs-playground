#include "Style.h"

#include <iostream>

// This is implemented in Rust.
extern "C" Style* ComputeStyle();
extern "C" void FreeStyle(Style*);

extern "C" int main_cpp()
{
  auto* style = ComputeStyle();
  std::cout << "Got a color: " << style->m_color->m_color << std::endl;
  FreeStyle(style);
  return 0;
}
