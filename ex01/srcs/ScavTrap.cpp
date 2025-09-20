#include "ScavTrap.hpp"

// - Canonical Constructors - //

ScavTrap::ScavTrap() : ClapTrap() {
	initStats_(kDefaultHp, kDefaultEn, kDefaultAtk);
	std::cout << "ScavTrap " << _name << " constructed.\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	initStats_(kDefaultHp, kDefaultEn, kDefaultAtk);
	std::cout << "ScavTrap " << _name << " constructed.\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << _name << " copied.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << _name << " assigned.\n";
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destroyed.\n";
}

void ScavTrap::attack(const std::string& target) {
	if (_hp == 0u) {
		std::cout << "ScavTrap " << _name << " cannot attack (dead).\n";
		return;
	}
	if (_energy == 0u) {
		std::cout << "ScavTrap " << _name << " cannot attack (no energy).\n";
		return;
	}
		std::cout << "ScavTrap " << _name << " attacks " << target
				  << ", causing " << _atk << " points of damage!\n";
	--_energy;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
}
