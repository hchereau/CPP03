#include "ClapTrap.hpp"

// - Canonical constructors - //

ClapTrap::ClapTrap()
	: _name("unnamed"),
	  _hp(defaultHp_()),
	  _energy(defaultEnergy_()),
	  _atk(defaultAtk_())
{
	std::cout << "ClapTrap " << _name << " constructed (default).\n";
}
ClapTrap::ClapTrap(const std::string &name)
	: _name(name),
	  _hp(defaultHp_()),
	  _energy(defaultEnergy_()),
	  _atk(defaultAtk_())
{
	std::cout << "ClapTrap " << _name << " constructed.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name),
	  _hp(other._hp),
	  _energy(other._energy),
	  _atk(other._atk)
{
	std::cout << "ClapTrap " << _name << " copied.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other) {
		_name   = other._name;
		_hp     = other._hp;
		_energy = other._energy;
		_atk    = other._atk;
	}
	std::cout << "ClapTrap " << _name << " assigned.\n";
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed.\n";
}

// - Private helper methods - //

bool ClapTrap::canAct_(const char *action) const
{
	if (_hp == 0u) {
		std::cout << "ClapTrap " << _name << " cannot " << action << " (dead).\n";
		return false;
	}
	if (_energy == 0u) {
		std::cout << "ClapTrap " << _name << " cannot " << action << " (no energy).\n";
		return false;
	}
	return true;
}

void ClapTrap::spendEnergy_(unsigned int amount)
{
	_energy = (_energy >= amount) ? (_energy - amount) : 0u;
}

// - Public member functions - //

void ClapTrap::attack(const std::string& target)
{
	if (!canAct_("attack"))
		return;
	std::cout << "ClapTrap " << _name
			  << " attacks " << target
			  << ", causing " << _atk
			  << " points of damage!\n";
	spendEnergy_(1u);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	const unsigned int dealt = (amount < _hp) ? amount : _hp;
	_hp -= dealt;

	std::cout << "ClapTrap " << _name
			  << " takes " << dealt
			  << " points of damage! Remaining HP: "
			  << _hp << '\n';
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!canAct_("repair"))
	return;

	_hp += amount;
	spendEnergy_(1u);

	std::cout << "ClapTrap " << _name
			  << " repairs itself, recovering " << amount
			  << " HP! Total HP: " << _hp << '\n';
}

void ClapTrap::initStats_(unsigned int hp, unsigned int energy, unsigned int atk) {
	_hp = hp;
	_energy = energy;
	_atk = atk;
}
