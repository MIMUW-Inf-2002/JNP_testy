# Testy do 07_images

Są dwie rzeczy do przetestowania: poprawność functional i poprawność images.

## Program diff_bmp

Służy do porównania i obliczenia różnicy dwóch plików bmp (przynajmniej tych generowanych przez bmp.h).

Użycie: `./diff_bmp plik1.bmp plik2.bmp roznica.bmp`. Porównuje `plik1.bmp` i `plik2.bmp`.
Mówi, czy są takie same, czy są podobne, czy całkiem inne. Do pliku `roznica.bmp`
zapisywana jest bitmapa będąca wartością bezwzględną z różnicy kolorów w każdym pikselu.

Ponieważ istnieje floating point arithmetic, to otrzymane bitmapy mogą się 
odrobinę różnić w przypadku bardziej skomplikowanych testów. 
Dlatego też ten program stara się wykryć, czy pliki różnią się mało.

Jak test nie przeszedł, to najlepiej samemu porównać te obrazy, ale wynik różnicy
może pokazać, gdzie się różnią.

## Skrypt testujący

Aby działał w obecnej wersji, w folderze `original-images` należy umieścić obrazy,
jakie poprawny program ma wygenerować. Nazwa pliku musi być identyczna z nazwą
pliku tworzonego przez program.

Skrypt najpierw kompiluje, potem generuje wszystkie obrazy, a następnie je porównuje.
Porównuje wszystkie pliki z rozszerzeniem bmp w folderze build_tests, jeżeli nie
znajdzie pliku w original images, to zgłasza błąd.

## Dodawanie testów

Można rozszerzyć test.cc albo dodać nowy program do CMakeLists i skryptu testującego.
Albo też zrobić własny skrypt testujący.

Najlepiej, żeby szerokość obrazu była podzielna przez 4, bo pliki bmp mają padding
i nie wiem, czy bmp.h to uwzględnia.