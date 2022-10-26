# JNP_testy

To repozytorium zawiera studenckie testy do zadań z JNP1 w roku akademickim 2022/2023.

## Przygotowywanie i uruchamianie testów

Format i sposób uruchomienia testów zależy od specyfiki zadania.

#### 01_top7

_Pliki testowe_: Dla każdego testu powinny zostać stworzone trzy pliki: `test.in`, `test.out` oraz `test.err`.

_Testowanie_: Do testowania należy użyć pliku `test.sh` w następujący sposób:

`./test.sh ścieżka/do/skomilowanego/top7 ścieżkado/folderu/z/testami`

#### 02_hash

_Pliki testowe_: Testy korzystają z narzędzia `gtest`. Przykłady tworzenia testów zawarte są w katalogu `02_hash/tests`.

_Testowanie_: Uruchamiamy plik `test.sh` w następujący sposób:

`./test.sh ścieżka/do/folderu/z/rozwiązaniem`

Skrypt usuwa pliki hash.cc i hash.h w swojej lokalizacji!  
Podmienia je na linki stałe do faktycznych plików w innej lokalizacji. Dzięki temu CMake musi przebudować testy tylko jeśli zmienisz coś w `hash.h`

Skrypt `test.sh` przygotuje plik wykonywalny o nazwie `Tests` i umieści go w katalogu `build`.
Aby go uruchomić można wykonać:

```sh
./build/Tests
```
lub
```sh
cd build
./Tests
```
