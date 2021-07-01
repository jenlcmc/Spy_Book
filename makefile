all:
	g++ -std=c++11 -Wall -Wextra spyBook.cpp main.cpp -o main
clean:
	rm ./main
