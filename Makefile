all: test
test: OwnershipPtr.hpp example.cpp
	g++ OwnershipPtr.hpp example.cpp -o test
clean:
	rm test