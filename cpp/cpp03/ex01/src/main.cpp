/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:14:48 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 04:13:45 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void separator(const std::string &title)
{
	std::cout << std::endl << "===== " << title << " =====" << std::endl;
}

int	main(void)
{
	separator("PART 1 - ClapTrap (base behaviour)");

	ClapTrap karen("karen");
	karen.attack("felix");
	karen.takeDamage(5);
	karen.beRepaired(3);
	karen.takeDamage(100);
	karen.attack("felix");   // must fail: no hp
	karen.beRepaired(5);     // must fail: no hp

	ClapTrap rhumy("rhumy");
	for (int i = 0; i < 11; i++)
		rhumy.attack("felix"); // 10 succeed, 11th fails: no energy
	rhumy.beRepaired(5);       // must fail: no energy

	separator("PART 2 - ScavTrap construction chain");
	std::cout << "Creating a ScavTrap should print ClapTrap ctor, then ScavTrap ctor:" << std::endl;
	ScavTrap anish("anish");
	std::cout << anish.getName() << " -> hp:" << anish.getHitPoints()
		<< " ep:" << anish.getEnergyPoints() << " ad:" << anish.getDamagePoints() << std::endl;

	separator("PART 3 - ScavTrap default constructor");
	ScavTrap defaultScav;
	std::cout << defaultScav.getName() << " -> hp:" << defaultScav.getHitPoints()
		<< " ep:" << defaultScav.getEnergyPoints() << " ad:" << defaultScav.getDamagePoints() << std::endl;

	separator("PART 4 - ScavTrap attack() (own message, different from ClapTrap's)");
	anish.attack("felix");

	separator("PART 5 - guardGate()");
	anish.guardGate();

	separator("PART 6 - inherited takeDamage() / beRepaired() used on a ScavTrap");
	anish.takeDamage(70);
	anish.beRepaired(20);

	separator("PART 7 - ScavTrap hp depletion (must block attack/beRepaired at 0 hp)");
	anish.takeDamage(9999);
	anish.attack("felix");
	anish.beRepaired(10);

	separator("PART 8 - ScavTrap energy depletion (own attack() must also respect energy)");
	ScavTrap uki("uki");
	for (int i = 0; i < 51; i++)
		uki.attack("felix"); // 50 succeed, 51st fails: no energy
	std::cout << uki.getName() << " energy left: " << uki.getEnergyPoints() << std::endl;

	separator("PART 9 - Copy constructor (must chain: ClapTrap copy ctor, then ScavTrap copy ctor)");
	ScavTrap fefe("fefe");
	fefe.takeDamage(30);
	ScavTrap fefeCopy(fefe);
	std::cout << fefeCopy.getName() << " (copy) hp:" << fefeCopy.getHitPoints()
		<< " ep:" << fefeCopy.getEnergyPoints() << std::endl;

	separator("PART 10 - operator=");
	ScavTrap assignedScav;
	assignedScav = fefe;
	std::cout << assignedScav.getName() << " (assigned) hp:" << assignedScav.getHitPoints()
		<< " ep:" << assignedScav.getEnergyPoints() << std::endl;

	separator("PART 11 - Self-assignment (a = a) must not break anything");
	assignedScav = assignedScav;
	std::cout << assignedScav.getName() << " still hp:" << assignedScav.getHitPoints() << std::endl;

	separator("PART 12 - Destruction chain (must destroy ScavTrap first, then ClapTrap)");
	std::cout << "Entering a scope with a ScavTrap..." << std::endl;
	{
		ScavTrap scoped("scoped");
		scoped.attack("felix");
	}
	std::cout << "-- back in main, scoped ScavTrap was destroyed above --" << std::endl;

	separator("End of main, remaining objects get destroyed now");
	return (0);
}