#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name)
: ClapTrap(name) {
	// Réglage des stats via l’API protégée (Option B)
	setStats(100, 100, 30);
	std::cout << "FragTrap " << getName() << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other) {
	std::cout << "FragTrap copy-constructed from " << other.getName() << "!" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap assigned from " << other.getName() << "!" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << getName() << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (canAct()) {
		std::cout << "FragTrap " << getName()
				  << " blasts " << target
				  << ", dealing " << getAttackDamage()
				  << " damage!" << std::endl;
		consumeEnergy(1);
	} else {
		std::cout << "FragTrap " << getName()
				  << " cannot attack (no energy or dead)." << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << getName()
			  << " requests high fives!" << std::endl;
}
