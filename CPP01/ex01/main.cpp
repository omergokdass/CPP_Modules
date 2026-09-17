#include "Zombie.hpp"

int main( void ) {
	int count = 5;
	std::cout << "--- Creating horde of " << count << " zombies ---" << std::endl;

	Zombie* horde = zombieHorde(count, "HordeZombie");
	horde[4].setName("omer");
	if (horde) {
		for (int i = 0; i < count; i++) {
			std::cout << i + 1 << ". ";
			horde[i].announce();
		}
		delete[] horde;
	}
	
	return 0;
}
