#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	a.attack("Beta");
	b.takeDamage(3);
	b.beRepaired(2);

	b.attack("Alpha");
	a.takeDamage(5);

	return 0;
}
