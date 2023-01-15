g++ -std=c++20 -Wall -Wextra -O2 -o worldcup test.cc
if [ $? -eq 0 ]
    then ./worldcup
    else echo "Compilation failed. Try again manually with g++ -std=c++2a -Wall -Wextra -O2 -o worldcup test.cc && ./worldcup"
fi