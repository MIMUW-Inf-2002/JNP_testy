#include "bmp.h"
#include "../images.h"
#include <cstdint>
#include <fstream>
#include <string>

namespace {
// Należy unikać niestandardowych rozszerzeń kompilatora, ale poniższe są
// powszechnie stosowane – a także użyteczne w rozwiązaniu problemu zapisu do
// pliku binarnego. Więcj informacji:
// https://en.wikipedia.org/wiki/Data_structure_alignment
#pragma pack(push)
#pragma pack(2)
    class BMP_header
    {
    public:
        BMP_header(const uint32_t width, const uint32_t height) :
                bfSize(sizeof(BMP_header) + data_size(width, height) + sizeof(Padding) * height),
                biWidth(width),
                biHeight(height)
        {}

        // Ten operator jest przeznaczony do użycia z binarnym zapisem do pliku.
        const char* operator&() const
        {
            return reinterpret_cast<const char*>(this);
        }

    private:
        using Padding = uint16_t;

        static uint32_t data_size(const uint32_t width, const uint32_t height)
        {
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

void
create_BMP(const std::string& filename,
           const uint32_t width,
           const uint32_t height,
           const Image& f)
{
    const BMP_header header(width, height);
    std::ofstream file(filename.c_str(),
                       std::ios::out | std::ios::trunc | std::ios::binary);
    file.write(&header, sizeof(header));
    for (uint32_t j = 0; j < height; j++) {
        for (uint32_t i = 0; i < width; i++) {
            Point p(static_cast<Coordinate>(i) - (width / 2),
                    static_cast<Coordinate>(j) - (height / 2));
            const Color c(f(p));
            file.write(reinterpret_cast<const char*>(c.data.data()), 3);
        }
    }
}
