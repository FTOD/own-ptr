all: test
test: OwnershipPtr.hpp example.cpp
	g++ OwnershipAwarePtr.hpp example.cpp -o test
clean:
	rm test