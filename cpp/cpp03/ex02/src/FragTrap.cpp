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

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " raises a hand, waiting for a high five!" << std::endl;
}