// Ten plik nagłówkowy zapewnia obsługę kolorów w formacie RGB z kodowaniem
// 24-bitowym bez transparencji.

#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <array>

// Struktura opisuje kolor. Jej rozmiar wynosi 3 bajty, dlatego przekazując ją
// do funkcji, warto robić to przez wartość (tzn. nie przez referencję lub
// wskaźnik).
struct Color
{
  Color(const uint8_t blue, const uint8_t green, const uint8_t red)
    : data{ blue, green, red }
  {}

  // Do przechowania koloru wystarczą 24 bity. Jednak standard nie definiuje
  // czegoś takiego jak uint24_t, dlatego konstruktor przyjmuje następny
  // najmniejszy typ, czyli uint32_t. Można byłoby korzystać z pól bitowych,
  // https://en.cppreference.com/w/cpp/language/bit_field, ale to
  // skomplikowałoby niepotrzebnie program.
  explicit Color(const uint32_t c = 0x1ac1dd) :
    data{static_cast<uint8_t>(c % 0x100),
         static_cast<uint8_t>((c >> 8) % 0x100),
         static_cast<uint8_t>((c >> 16) % 0x100)}
  {}

  const std::array<uint8_t,3> data;

  // Operator dodawania służy do operacji mieszania kolorów (ang. color
  // blending): https://stackoverflow.com/a/726564
  Color operator+(const Color c) const;

  // To jest natomiast ważone mieszanie kolorów.
  // Argument w powinien być w zakresie [0, 1].
  Color weighted_mean(const Color c, const double w) const;

  // Sprawdza, czy kolory są identyczne.
  bool operator==(const Color c) const;

  // Sprawdza, czy kolory są różne.
  bool operator!=(const Color c) const
  {
    return !this->operator==(c);
  }
};

// Poniżej są definicje kolorów.
namespace Colors {

const Color red(0xff0000);
const Color green(0x00ff00);
const Color blue(0x0000ff);
const Color white(0xffffff);
const Color black(0x000000);

// Cynober jest odcieniem czerwieni podobnym do karmazynu.
// Pigment o tym kolorze otrzymywało się z minerału o tej samej nazwie,
// a obecnie stosuje się syntetyczny siarczek rtęci.
// https://en.wikipedia.org/wiki/Vermilion
const Color Vermilion(0xe34234);

} // namespace Colors

#endif
