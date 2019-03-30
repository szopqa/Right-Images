run: main-cpp-17
	cd src && ./main

main-cpp-17:
	cd src && g++ -std=gnu++17 main.cpp -o main -lstdc++fs
