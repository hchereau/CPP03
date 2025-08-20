#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "ClapTrap " << this->name << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << this->name << " assigned!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "ClapTrap " << name
				  << " attacks " << target
				  << ", causing " << attackDamage
				  << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " cannot attack (no energy or dead)." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	hitPoints -= amount;
	if (hitPoints < 0) hitPoints = 0;
	std::cout << "ClapTrap " << name
			  << " takes " << amount
			  << " points of damage! Remaining HP: "
			  << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name
				  << " repairs itself, recovering "
				  << amount << " HP! Total HP: "
				  << hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " cannot repair (no energy or dead)." << std::endl;
	}
}

const std::string& ClapTrap::getName() const { return name; }
int  ClapTrap::getHitPoints() const { return hitPoints; }
int  ClapTrap::getEnergyPoints() const { return energyPoints; }
int  ClapTrap::getAttackDamage() const { return attackDamage; }

void ClapTrap::setStats(int hp, int ep, int ad) {
	hitPoints = hp;
	energyPoints = ep;
	attackDamage = ad;
}

bool ClapTrap::canAct() const {
	return hitPoints > 0 && energyPoints > 0;
}

void ClapTrap::consumeEnergy(unsigned int n) {
	int consume = static_cast<int>(n);
	energyPoints = (energyPoints >= consume) ? (energyPoints - consume) : 0;
}
