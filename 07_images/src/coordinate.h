// Ten plik nagłówkowy zapewnia obsługę układu współrzędnych (ang. coordinate
// system).

#ifndef COORDINATE_H
#define COORDINATE_H

#include <utility>

// Ten typ reprezentuje współrzędną w pewnym układzie. W tym programie używane
// są współrzędne kartezjańskie (domyślne) oraz biegunowe (okazjonalnie).
using Coordinate = double;

// Struktura przetrzymująca współrzędne punktu na R^2 obsługuje obydwa układy
// współrzędnych.
struct Point
{
  Point(const Coordinate f, const Coordinate s, const bool p = false) :
    first(f),
    second(s),
    is_polar(p)
  {}

  const Coordinate first;  // Współrzędna: x lub rho
  const Coordinate second; //              y lub phi
  const bool is_polar;     // Czy układ współrzędnych jest biegunowy?
};

// Wektor w tym programie służy do opisu przesunięć w kartezjańskim układzie
// współrzędnych.
using Vector = std::pair<double, double>;

// Zamienia współrzędne punktu z kartezjańskich na biegunowe.
// Zakłada, że p jest we współrzędnych kartezjańskich.
Point
to_polar(const Point p);

// Zamienia współrzędne punktu z biegunowych na kartezjańskie.
// Zakłada, że p jest we współrzędnych biegunowych.
Point
from_polar(const Point p);

// Oblicza odległość między dwoma punktami lub między punktem a początkiem
// układu współrzędnych.
double
distance(const Point p, const Point q = {0, 0});

#endif
