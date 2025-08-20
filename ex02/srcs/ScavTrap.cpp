#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name) {
	// ⚙️ Réglage des stats via l’API protégée de ClapTrap
	setStats(100, 50, 20);
	std::cout << "ScavTrap " << getName() << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other) {
	std::cout << "ScavTrap copy-constructed from " << other.getName() << "!" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap assigned from " << other.getName() << "!" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << getName() << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	// 🔁 On utilise l’API protégée pour respecter les invariants
	if (canAct()) {
		std::cout << "ScavTrap " << getName()
				  << " slashes " << target
				  << ", dealing " << getAttackDamage()
				  << " damage!" << std::endl;
		consumeEnergy(1);
	} else {
		std::cout << "ScavTrap " << getName()
				  << " cannot attack (no energy or dead)." << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " has entered Gate keeper mode." << std::endl;
}

