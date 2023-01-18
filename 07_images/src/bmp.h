#ifndef BMP_H
#define BMP_H

#include "../images.h"
#include <cstdint>
#include <string>

void
create_BMP(const std::string& filename,
           const uint32_t width,
           const uint32_t height,
           const Image& f);

#endif
