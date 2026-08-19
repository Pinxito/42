/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 03:05:03 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 03:39:17 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor is called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor is called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor is called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " cannot attack, it has no hit points left!" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " cannot attack " << target << ", it has no energy left!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->_name << " is now in Gate keeper mode!" << std::endl;
}