/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 03:03:55 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 03:39:42 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setDamagePoints(30);
	std::cout << "FragTrap default constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setDamagePoints(30);
	std::cout << "FragTrap  " << this->getName() << " constructed!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor is called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor is called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}


void	FragTrap::attack(const std::string &target)
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
	std::cout << "FragTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getDamagePoints() << " points of damage!" << std::endl;
	int newEnergy = this->getEnergyPoints() - 1;
	this->setEnergyPoints(newEnergy);
}


void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " is already down, it cannot take more damage" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
	if (amount >= (unsigned int)this->getHitPoints())
		this->setHitPoints(0);
	else
	{
		int newHitPoints = this->getHitPoints() - amount;
		this->setHitPoints(newHitPoints);
	}
	if (this->getHitPoints() == 0)
		std::cout << "FragTrap " << this->getName() << " has no hit points left!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " cannot be repaired, it has no hit points left!" << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " cannot be repaired, it has no energy left!" << std::endl;
		return ;
	}
	int newHitPoints = this->getHitPoints() + amount;
	this->setHitPoints(newHitPoints);
	int newEnergyPoints = this->getEnergyPoints() - 1;
	this->setEnergyPoints(newEnergyPoints);
	std::cout << "FragTrap " << this->getName() << " is repaired and gains " << amount << " hit points!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " raises a hand, waiting for a high five!" << std::endl;
}