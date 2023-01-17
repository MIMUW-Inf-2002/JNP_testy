#include "color.h"
#include <cassert>
#include <cstdint>

Color
Color::operator+(const Color c) const
{
  // Następuje tymczasowe rozszerzenie typu dla zachowania precyzji obliczeń.
  const uint8_t new_data[3] = {
    static_cast<uint8_t>((uint16_t(c.data[0]) + uint16_t(this->data[0])) / 2),
    static_cast<uint8_t>((uint16_t(c.data[1]) + uint16_t(this->data[1])) / 2),
    static_cast<uint8_t>((uint16_t(c.data[2]) + uint16_t(this->data[2])) / 2)
  };
  return Color(new_data[0], new_data[1], new_data[2]);
}

Color
Color::weighted_mean(const Color c, const double w) const
{
  assert(w >= 0. && w <= 1.);
  const uint8_t new_data[3] = {
    static_cast<uint8_t>(c.data[0] * w + this->data[0] * (1 - w)),
    static_cast<uint8_t>(c.data[1] * w + this->data[1] * (1 - w)),
    static_cast<uint8_t>(c.data[2] * w + this->data[2] * (1 - w))
  };
  return Color(new_data[0], new_data[1], new_data[2]);
}

bool
Color::operator==(const Color c) const
{
  return c.data[0] == this->data[0] &&
         c.data[1] == this->data[1] &&
         c.data[2] == this->data[2];
}
