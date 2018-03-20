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

enum StyleFloat : uint8_t
{
  None,
  Left,
  Right,
};

struct StyleDisplay
{
  StyleFloat m_float;
};
