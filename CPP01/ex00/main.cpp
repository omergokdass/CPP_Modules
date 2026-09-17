#include "Zombie.hpp"

int main( void ) {
	std::cout << "--- Heap Allocation Test ---" << std::endl;
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "\n--- Stack Allocation Test ---" << std::endl;
	randomChump("StackZombie");

	return 0;
}
