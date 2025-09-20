#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// Draine suffisamment d'énergie pour forcer le "no energy"
static void drain_energy(ClapTrap& x, int times) {
	for (int i = 0; i < times; ++i) x.attack("dummy");
}

static void sep(const char* title) {
	std::cout << "\n==== " << title << " ====\n";
}

int main() {
	sep("ClapTrap - base behavior");
	{
		ClapTrap c("Clappy");
		c.attack("dummy");		  // 0 dmg (si _atk = 0)
		c.takeDamage(3u);		   // HP = 7
		c.beRepaired(2u);		   // HP = 9
		c.takeDamage(1000u);		// clamp -> HP = 0
		c.attack("dummy");		  // dead
		c.beRepaired(5u);		   // dead
	}

	sep("ScavTrap - derived behavior + guardGate");
	{
		ScavTrap s("Serena");
		s.attack("intruder");	   // 20 dmg
		s.takeDamage(42u);		  // HP = 58
		s.beRepaired(10u);		  // HP = 68
		s.guardGate();			  // mode spécial

		std::cout << "-- energy drain --\n";
		drain_energy(s, 60);		// finir l’énergie
		s.beRepaired(1u);		   // no energy
	}

	sep("ScavTrap - copy & assign");
	{
		ScavTrap a("A");
		ScavTrap b = a;			 // copy ctor
		ScavTrap d("D");
		d = a;					  // operator=
		(void)b; (void)d;
	}

	sep("FragTrap - derived behavior + highFivesGuys");
	{
		FragTrap f("Frago");
		f.attack("target");		  // 30 dmg si stats par défaut
		f.takeDamage(77u);		  // HP diminue
		f.beRepaired(12u);		  // heal et -1 énergie
		f.highFivesGuys();		  // capacité spéciale

		std::cout << "-- energy drain --\n";
		drain_energy(f, 120);	   // beaucoup d’attaques -> plus d’énergie
		f.attack("target");		   //  "no energy"
		f.beRepaired(1u); 		   //"no energy" si HP>0
	}

	sep("FragTrap - copy & assign");
	{
		FragTrap x("X");
		FragTrap y = x;			 // copy ctor
		FragTrap z("Z");
		z = x;					  // operator=
		(void)y; (void)z;
	}

	sep("Construction/Destruction chaining (scopes)");
	{
		FragTrap scopedFrag("Scoped");
		{
			ScavTrap inner("Inner");
			inner.guardGate();
		}
		scopedFrag.highFivesGuys();
	}

	sep("Done");
	return 0;
}
