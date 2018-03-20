#pragma once

#include <cstdint>

typedef uint32_t nscolor;

// This is manual, and converting from the Rust type to nscolor is cheap, but
// unnecessary.
//
// (In more complex cases, it's not cheap at all).
struct StyleColor
{
  nscolor m_color;
};
