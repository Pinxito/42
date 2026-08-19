/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 20:34:16 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 04:14:49 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void separator(const std::string &title)
{
	std::cout << std::endl << "===== " << title << " =====" << std::endl;
}

int	main(void)
{
	separator("1. Default constructor");
	ClapTrap defaultTrap;
	std::cout << defaultTrap.getName() << " -> hp:" << defaultTrap.getHitPoints()
		<< " ep:" << defaultTrap.getEnergyPoints() << " ad:" << defaultTrap.getDamagePoints() << std::endl;

	separator("2. Parameterized constructor");
	ClapTrap karen("karen");
	std::cout << karen.getName() << " -> hp:" << karen.getHitPoints()
		<< " ep:" << karen.getEnergyPoints() << " ad:" << karen.getDamagePoints() << std::endl;

	separator("3. Normal attack()");
	karen.attack("felix");

	separator("4. Normal takeDamage()");
	karen.takeDamage(5);

	separator("5. Normal beRepaired()");
	karen.beRepaired(3);

	separator("6. takeDamage() bringing hp exactly to 0");
	karen.takeDamage(8); // hp: 8 -> 0

	separator("7. attack() while hp == 0 (must fail)");
	karen.attack("felix");

	separator("8. beRepaired() while hp == 0 (must fail)");
	karen.beRepaired(10);

	separator("9. takeDamage() with amount bigger than current hp (must clamp to 0, not negative)");
	ClapTrap fragile("fragile");
	fragile.takeDamage(9999);
	std::cout << fragile.getName() << " hp after huge damage: " << fragile.getHitPoints() << std::endl;

	separator("10. Energy depletion (10 successful attacks, 11th must fail)");
	ClapTrap rhumy("rhumy");
	for (int i = 0; i < 11; i++)
		rhumy.attack("felix");
	std::cout << rhumy.getName() << " energy left: " << rhumy.getEnergyPoints() << std::endl;

	separator("11. beRepaired() with 0 energy but hp > 0 (must fail)");
	rhumy.beRepaired(5);

	separator("12. Copy constructor");
	ClapTrap fefe("fefe");
	fefe.takeDamage(4);
	ClapTrap fefeCopy(fefe);
	std::cout << fefeCopy.getName() << " (copy) hp:" << fefeCopy.getHitPoints()
		<< " ep:" << fefeCopy.getEnergyPoints() << std::endl;

	separator("13. operator=");
	ClapTrap assigned;
	assigned = fefe;
	std::cout << assigned.getName() << " (assigned) hp:" << assigned.getHitPoints()
		<< " ep:" << assigned.getEnergyPoints() << std::endl;

	separator("14. Self-assignment (a = a) must not break anything");
	assigned = assigned;
	std::cout << assigned.getName() << " still hp:" << assigned.getHitPoints() << std::endl;

	separator("15. Destructor calls happen when leaving scope");
	{
		ClapTrap scoped("uki");
		scoped.attack("felix");
	}
	std::cout << "-- back in main, scoped ClapTrap was destroyed above --" << std::endl;

	separator("End of main, remaining objects get destroyed now");
	return (0);
}