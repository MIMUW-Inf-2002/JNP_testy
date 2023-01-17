#include "coordinate.h"
#include <cassert>
#include <cmath>

Point
to_polar(const Point p)
{
  assert(!p.is_polar);
  auto x = std::atan2(p.second, p.first);
  return Point(distance(p), x >= 0 ? x : (2 * M_PI + x), true);
}

Point
from_polar(const Point p)
{
  assert(p.is_polar);
  return Point(p.first * std::cos(p.second), p.first * std::sin(p.second), false);
}

double
distance(const Point p, const Point q)
{
  assert(!p.is_polar && !q.is_polar);
  return std::sqrt(std::pow(p.first - q.first, 2) + std::pow(p.second - q.second, 2));
}
