#include "FragTrap.hpp"

// -- Canonical constructors -- //

FragTrap::FragTrap() : ClapTrap() {
	initStats_(kDefaultHp, kDefaultEn, kDefaultAtk);
	std::cout << "FragTrap " << _name << " constructed.\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	initStats_(kDefaultHp, kDefaultEn, kDefaultAtk);
	std::cout << "FragTrap " << _name << " constructed.\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << _name << " copied.\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << _name << " assigned.\n";
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destroyed.\n";
}

// -- Overrides -- //

void FragTrap::attack(const std::string& target) {
	if (_hp == 0u) {
		std::cout << "FragTrap " << _name << " cannot attack (dead).\n";
		return;
	}
	if (_energy == 0u) {
		std::cout << "FragTrap " << _name << " cannot attack (no energy).\n";
		return;
	}
	std::cout << "FragTrap " << _name << " attacks " << target
			  << ", causing " << _atk << " points of damage!\n";
	--_energy;
}

// -- Special ability -- //

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests a positive high five!\n";
}
