/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:12:50 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 04:08:21 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setDamagePoints(20);
	std::cout << "ScavTrap default constructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setDamagePoints(20);
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
	if (this->getHitPoints() <= 0)
	{
		std::cout << this->getName() << " cannot attack, it has no hit points left!" << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << this->getName() << " cannot attack " << target << ", it has no energy left!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getDamagePoints() << " points of damage!" << std::endl;
	int newEnergy = this->getEnergyPoints() - 1;
	this->setEnergyPoints(newEnergy);
}


void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is already down, it cannot take more damage" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
	if (amount >= (unsigned int)this->getHitPoints())
		this->setHitPoints(0);
	else
	{
		int newHitPoints = this->getHitPoints() - amount;
		this->setHitPoints(newHitPoints);
	}
	if (this->getHitPoints() == 0)
		std::cout << "ScavTrap " << this->getName() << " has no hit points left!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " cannot be repaired, it has no hit points left!" << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " cannot be repaired, it has no energy left!" << std::endl;
		return ;
	}
	int newHitPoints = this->getHitPoints() + amount;
	this->setHitPoints(newHitPoints);
	int newEnergyPoints = this->getEnergyPoints() - 1;
	this->setEnergyPoints(newEnergyPoints);
	std::cout << "ScavTrap " << this->getName() << " is repaired and gains " << amount << " hit points!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->getName() << " is now in Gate keeper mode!" << std::endl;
}