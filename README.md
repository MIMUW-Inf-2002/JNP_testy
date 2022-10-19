# JNP_testy

To repozytorium zawiera studenckie testy do zadań z JNP1 w roku akademickim 2022/2023.

## Instrukcja dodawania testów

Obowiązują zasady takie jak na IPP w poprzednim semestrze.

Testy do zadania dodajemy w odpowiednim folderze jako podkatalog.
Konkretny wygląd testów (czy są to funkcje main w cpp, czy może pliki in i out)
zależy od specyfiki zadania.

## Używanie `git-lfs`

Niektóre testy są bardzo duże i zostały skompresowane do plików `.zip` aby zajmowały mniej miejsca.
Pliki `.zip` nie są trzymane w głównym repozytorium i zarządza nimi narzędzie `git-lfs`.

Przykładem takich testów są testy `01_top7/rentib/fat.zip`.

Aby otrzymać dostęp do takich testów należy.

1. Zainstalować pakiet `git-lfs` (np. `sudo apt install git-lfs)
2. Sklonować repo przy użyciu komendy `git` (normalnie)
3. Wywołać w repo polecenie `git lfs pull`, która pobierze dodatkowe pliki
