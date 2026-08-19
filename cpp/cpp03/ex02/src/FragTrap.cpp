/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 03:03:55 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 11:53:48 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap constructor is called" << std::endl;
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
	std::cout << "FragTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " raises a hand, waiting for a high five!" << std::endl;
}