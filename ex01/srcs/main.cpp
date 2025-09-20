#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void drain_energy(ClapTrap& x) {
	for (int i = 0; i < 51; ++i) x.attack("dummy");
}

int main() {
	ClapTrap c("Clappy");
	c.attack("dummy");		  // 0 dmg
	c.takeDamage(3u);		   // HP = 7
	c.beRepaired(2u);		   // HP = 9
	c.takeDamage(1000u);		// clamp -> HP = 0
	c.attack("dummy");		  // dead
	c.beRepaired(5u);		   // dead

	std::cout << "----\n";

	ScavTrap s("Serena");
	s.attack("intruder");	   // 20 dmg
	s.takeDamage(42u);		  // HP = 58
	s.beRepaired(10u);		  // HP = 68
	s.guardGate();			  // mod special

	std::cout << "----\n";

	ScavTrap e("Exhaust");
	drain_energy(e);			// “no energy” à la fin
	e.beRepaired(1u);		   // “no energy”

	std::cout << "----\n";

	ScavTrap a("A");
	ScavTrap b = a;
	ScavTrap d("D");
	d = a;
}
