#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap c("Clappy");
	c.attack("dummy");
	c.takeDamage(3);
	c.beRepaired(2);

	std::cout << "----" << std::endl;

	ScavTrap s("Serena");
	s.attack("intruder");
	s.takeDamage(42);
	s.beRepaired(10);
	s.guardGate();

	return 0;
}

