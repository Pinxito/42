/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:14:48 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/14 23:22:22 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
int main()
{
	// ClapTrap lol("Julien");
	ScavTrap scav("Bernard");
	scav.attack("lol");
	scav.attack("Robert");
	std::cout << scav.getName() << " energy points left " << scav.getEnergyPoints() << " hits points left " << scav.getHitPoints() << " damage points left " << scav.getDamagePoints() << std::endl;
	scav.beRepaired(10);
	scav.takeDamage(10);
	scav.takeDamage(10);
	std::cout << scav.getName() << " energy points left " << scav.getEnergyPoints() << " hits points left " << scav.getHitPoints() << " damage points left " << scav.getDamagePoints() << std::endl;
	scav.beRepaired(10);
	scav.beRepaired(1);
	scav.attack("Yoan");
	scav.attack("Yyo");
}