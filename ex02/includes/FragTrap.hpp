#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		// Constructors/destructor
		FragTrap();
		explicit FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		// Overrides
		void attack(const std::string& target);

		// special ability
		void highFivesGuys(void);

	private:
		// defaults stats | membres de classe statiques constants.
		static const unsigned int kDefaultHp = 100u;
		static const unsigned int kDefaultEn = 100u;
		static const unsigned int kDefaultAtk = 30u;
};

#endif
