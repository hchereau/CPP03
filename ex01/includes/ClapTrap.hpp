#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
	std::string name;
	int		 hitPoints;
	int		 energyPoints;
	int		 attackDamage;

protected:
	void setStats(int hp, int ep, int ad);
	bool canAct() const;
	void consumeEnergy(unsigned int n);

public:
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	const std::string& getName() const;
	int  getHitPoints() const;
	int  getEnergyPoints() const;
	int  getAttackDamage() const;
};

#endif
