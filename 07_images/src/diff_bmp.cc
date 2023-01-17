/* Program do porównania dwóch plików BMP
 * Do pisania używamy dostarczonego kodu
 * Ten kod jest przydki i nie działa dla wszystkich plików BMP,
 * ale na potrzeby zadania powinien wystarczyć.
 */

#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

constexpr const char *RESET = "\x1B[0m";
constexpr const char *RED = "\x1B[91;1m";
constexpr const char *GREEN = "\x1B[92;1m";

namespace {
// Należy unikać niestandardowych rozszerzeń kompilatora, ale poniższe są
// powszechnie stosowane – a także użyteczne w rozwiązaniu problemu zapisu do
// pliku binarnego. Więcj informacji:
// https://en.wikipedia.org/wiki/Data_structure_alignment
#pragma pack(push)
#pragma pack(2)
class BMP_header {
public:
  BMP_header(const uint32_t width, const uint32_t height)
      : bfSize(sizeof(BMP_header) + data_size(width, height) +
               sizeof(Padding) * height),
        biWidth(width), biHeight(height) {}

  // Ten operator jest przeznaczony do użycia z binarnym zapisem do pliku.
  const char *operator&() const { return reinterpret_cast<const char *>(this); }

private:
  using Padding = uint16_t;

  static uint32_t data_size(const uint32_t width, const uint32_t height) {
    return width * height * 3;
  }

  // Jako wyjątek przyjęto poniższą konwencję nazewniczą wziętą ze strony
  // z dokumentacją formatu BMP: http://tiny.cc/xg0agz
  //
  // *** Nagłówek pliku (struktura BITMAPFILEHEADER) ***
  // - pole o wartości "BM" deklarujące plik typu BMP
  const uint16_t bfType = 19778; // 19778 == 0x4d42 == 'B''M'
  // - rozmiar pliku w bajtach
  const uint32_t bfSize;
  // - pole zarezerwowane, musi być równe 0
  const uint16_t bfReserved1 = 0;
  // - pole zarezerwowane, musi być równe 0
  const uint16_t bfReserved2 = 0;
  // - przesunięcie (offset) od początku pliku do danych mapy bitowej
  const uint32_t bfOffBits = 54;
  // *** Nagłówek "info" (struktura BITMAPINFOHEADER) ***
  // - rozmiar struktury BITMAPINFOHEADER w bajtach
  const uint32_t biSize = 40;
  // - szerokość obrazu w pikselach
  const uint32_t biWidth;
  // - wysokość obrazu w pikselach
  const uint32_t biHeight;
  // - liczba płaszczyzn na urządzeniu docelowym
  //   Według dokumentu:
  //   https://devblogs.microsoft.com/oldnewthing/20041201-00/?p=37163
  //   poniższe pole powinno mieć wartość 1.
  const uint16_t biPlanes = 1;
  // - liczba bitów na piksel (1 – czarno-białe; 4 – 16 kolorów;
  //   8 – 256 kolorów; 24 – ok. 16,7 milionów kolorów)
  const uint16_t biBitCount = 24;
  // - typ kompresji; 0 oznacza brak kompresji
  //   Uwaga: kompresji w plikach BMP praktycznie się nie spotyka.
  const uint32_t biCompression = 0;
  // - rozmiar danych obrazu w bajtach; jeśli nie ma kompresji, to można
  //   ustawić wartość 0
  const uint32_t biSizeImage = 0;
  // - horyzontalna liczba pikseli na metr docelowego urządzenia;
  //   można ustawić wartość 0
  const uint32_t biXPelsPerMeter = 0;
  // - wertykalna liczba pikseli na metr docelowego urządzenia;
  //   można ustawić wartość 0
  const uint32_t biYPelsPerMeter = 0;
  // - liczba kolorów użyta w bitmapie;
  //   wartość 0 spowoduje automatyczne obliczenie na podstawie
  //   pola biBitCount
  const uint32_t biClrUsed = 0;
  // - liczba „ważnych” kolorów w bitmapie;
  //   wartość 0 oznacza, że wszystkie kolory są ważne
  const uint32_t biClrImportant = 0;
};
#pragma pack(pop) // Tu się kończy niestandardowe zachowanie.
} // namespace

void create_BMP(const std::string &filename, const uint32_t width,
                const uint32_t height, char ***im) {
  const BMP_header header(width, height);
  std::ofstream file(filename.c_str(),
                     std::ios::out | std::ios::trunc | std::ios::binary);
  file.write(&header, sizeof(header));
  for (uint32_t j = 0; j < height; j++) {
    for (uint32_t i = 0; i < width; i++) {
      file.write(reinterpret_cast<const char *>(im[i][j]), 3);
    }
  }
}

struct bitmap {
  int width;
  int height;
  char ***bmp;
};

bitmap read_BMP(const std::string &filename) {
  std::ifstream f;
  f.open(filename, std::ios::in | std::ios::binary);
  if (!f.is_open()) {
    std::cerr << "File: " + filename + " could not be opened!" << std::endl;
    return {0, 0, nullptr};
  }
  unsigned char fileHeader[14];
  f.read(reinterpret_cast<char *>(fileHeader), 14);
  unsigned char informationHeader[40];
  f.read(reinterpret_cast<char *>(informationHeader), 40);

  // int fileSize = fileHeader[2] + (fileHeader[3] << 8) + (fileHeader[4] << 16)
  // + (fileHeader[5] << 24);

  int width = informationHeader[4] + (informationHeader[5] << 8) +
              (informationHeader[6] << 16) + (informationHeader[7] << 24);
  int height = informationHeader[8] + (informationHeader[9] << 8) +
               (informationHeader[10] << 16) + (informationHeader[11] << 24);
  int bits_per_pixel = informationHeader[14] + (informationHeader[15] << 8);

  if (bits_per_pixel != 24) {
    std::cerr << "Panic! : the file " + filename +
                     " has a non-standard amount of bits per pixel"
              << std::endl;
    f.close();
    return {0, 0, nullptr};
  }

  int padding = ((4 - (width * 3) % 4) % 4);

  char ***bitmap = new char **[width];
  for (int i = 0; i < width; i++) {
    bitmap[i] = new char *[height];
    for (int j = 0; j < height; j++) {
      bitmap[i][j] = new char[3];
    }
  }

  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      f.read(bitmap[i][j], 3);
    }
    f.ignore(padding);
  }

  f.close();
  return {width, height, bitmap};
}

void freeBmp(char ***bmp, int width, int height) {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      delete[] bmp[i][j];
    }
    delete[] bmp[i];
  }
  delete[] bmp;
}

char absdiff(char c1, char c2) {
  int i1 = static_cast<unsigned char>(c1);
  int i2 = static_cast<unsigned char>(c2);
  if (i1 > i2) {
    int diff = i1 - i2;
    return static_cast<char>(diff);
  }
  int diff = i2 - i1;
  return static_cast<char>(diff);
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Usage: ./diff_bmp <first_file_path> <second_file_path> "
                 "<result_path>"
              << std::endl;
    return 2;
  }
  std::string file1 = argv[1];
  std::string file2 = argv[2];
  std::string fileOut = argv[3];
  bitmap bmp1 = read_BMP(file1);
  if (bmp1.bmp == nullptr) {
    return 2;
  }
  bitmap bmp2 = read_BMP(file2);
  if (bmp2.bmp == nullptr) {
    freeBmp(bmp1.bmp, bmp1.width, bmp1.height);
    return 2;
  }
  if (bmp1.height != bmp2.height || bmp1.width != bmp2.width) {
    std::cerr << "Files have different resolutions!" << std::endl;
    freeBmp(bmp1.bmp, bmp1.width, bmp1.height);
    freeBmp(bmp2.bmp, bmp2.width, bmp2.height);
    return 2;
  }
  uint32_t width = bmp1.width;
  uint32_t height = bmp1.height;
  char ***diff = new char **[width];
  for (uint32_t i = 0; i < width; i++) {
    diff[i] = new char *[height];
    for (uint32_t j = 0; j < height; j++) {
      diff[i][j] = new char[3];
    }
  }

  bool perfect = true;
  bool almost_perfect = true;

  for (uint32_t i = 0; i < width; i++) {
    for (uint32_t j = 0; j < height; j++) {
      for (uint32_t k = 0; k < 3; k++) {
        diff[i][j][k] = absdiff(bmp1.bmp[i][j][k], bmp2.bmp[i][j][k]);
        if (diff[i][j][k] != 0) {
          perfect = false;
          if (diff[i][j][k] != 1) {
            almost_perfect = false;
          }
          // diff[i][j][k] = -1;
        }
      }
    }
  }

  if (perfect) {
    std::cout << "Images are a perfect match!\n" << GREEN << "TEST PASSED"
              << RESET << std::endl;
  } else if (almost_perfect) {
    std::cout << "Difference between colors is at most one.\n"
              << GREEN << "TEST PASSED" << RESET << std::endl;
  } else {
    std::cout << "Checking for shift by one..." << std::endl;
    bool okay = true;
    for (uint32_t i = 0; i < width; i++) {
      for (uint32_t j = 0; j < height; j++) {
        if (i > 0 && i < width - 1 && j > 0 && j < height - 1) {
          for (uint32_t k = 0; k < 3; k++) {
            bool correct = false;
            char d;
            d = absdiff(bmp1.bmp[i][j][k], bmp2.bmp[i - 1][j - 1][k]);
            if (d <= 1) {
              correct = true;
            }
            d = absdiff(bmp1.bmp[i][j][k], bmp2.bmp[i - 1][j][k]);
            if (d <= 1) {
              correct = true;
            }
            d = absdiff(bmp1.bmp[i][j][k], bmp2.bmp[i - 1][j + 1][k]);
            if (d <= 1) {
              correct = true;
            }
            d = absdiff(bmp1.bmp[i][j][k], bmp2.bmp[i][j - 1][k]);
            if (d <= 1) {
              correct = true;
            }
            d = absdiff(bmp1.bmp[i][j][k], bmp2.bmp[i][j + 1][k]);
            if (d <= 1) {
              correct = true;
            }
            d = absdiff(bmp1.bmp[i][j][k], bmp2.bmp[i + 1][j - 1][k]);
            if (d <= 1) {
              correct = true;
            }
            d = absdiff(bmp1.bmp[i][j][k], bmp2.bmp[i + 1][j][k]);
            if (d <= 1) {
              correct = true;
            }
            d = absdiff(bmp1.bmp[i][j][k], bmp2.bmp[i + 1][j + 1][k]);
            if (d <= 1) {
              correct = true;
            }

            if (!correct) {
              okay = false;
            }
          }
          if (!okay) {
            break;
          }
        }
      }
      if (!okay) {
        break;
      }
    }
    if (okay) {
      std::cout << "Every pixel is a neighbour of a pixel with the correct "
                   "colour\n"
                << GREEN << "TEST PASSED" << RESET << std::endl;
    } else {
      std::cout << "Difference too large\n"
                << RED << "TEST FAILED" << RESET << std::endl;
      create_BMP(fileOut, width, height, diff);
      freeBmp(bmp1.bmp, width, height);
      freeBmp(bmp2.bmp, width, height);
      freeBmp(diff, width, height);
      return 1;
    }
  }

  create_BMP(fileOut, width, height, diff);
  freeBmp(bmp1.bmp, width, height);
  freeBmp(bmp2.bmp, width, height);
  freeBmp(diff, width, height);
  return 0;
}
