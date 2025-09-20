#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
public:
	// Constructors/destructor
	ClapTrap();
	explicit ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	// Public member functions
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	// Data members
	std::string	_name;
	unsigned int _hp;
	unsigned int _energy;
	unsigned int _atk;

	// Internal helper functions
	bool canAct_(const char* action) const; // Check if the ClapTrap can perform action
	void spendEnergy_(unsigned int amount); //deduct energy (clean version)

	// Default stats
	static unsigned int defaultHp_() 	{ return 10u; }
	static unsigned int defaultEnergy_(){ return 10u; }
	static unsigned int defaultAtk_()	{ return 0u; }
};

#endif
