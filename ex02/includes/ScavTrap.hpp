#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
public:
	// Constructors/destructors
	ScavTrap();
	explicit ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();

	// Public member functions
	void attack(const std::string& target);
	void guardGate();
private:
	static const unsigned int kDefaultHp  = 100u;
	static const unsigned int kDefaultEn  = 50u;
	static const unsigned int kDefaultAtk = 20u;
};

#endif
