/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 03:05:43 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 11:54:25 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	separator("PART 2 - ScavTrap construction chain (ClapTrap ctor, then ScavTrap ctor)");
	ScavTrap anish("anish");
	std::cout << anish.getName() << " -> hp:" << anish.getHitPoints()
		<< " ep:" << anish.getEnergyPoints() << " ad:" << anish.getDamagePoints() << std::endl;
	anish.attack("felix");
	anish.guardGate();
	anish.takeDamage(70);
	anish.beRepaired(20);

	separator("PART 3 - FragTrap construction chain (ClapTrap ctor, then FragTrap ctor)");
	FragTrap uki("uki");
	std::cout << uki.getName() << " -> hp:" << uki.getHitPoints()
		<< " ep:" << uki.getEnergyPoints() << " ad:" << uki.getDamagePoints() << std::endl;

	separator("PART 4 - FragTrap default constructor");
	FragTrap defaultFrag;
	std::cout << defaultFrag.getName() << " -> hp:" << defaultFrag.getHitPoints()
		<< " ep:" << defaultFrag.getEnergyPoints() << " ad:" << defaultFrag.getDamagePoints() << std::endl;

	separator("PART 5 - highFivesGuys()");
	uki.highFivesGuys();

	separator("PART 6 - inherited attack()/takeDamage()/beRepaired() used on a FragTrap");
	uki.attack("felix");
	uki.takeDamage(90);
	uki.beRepaired(10);

	separator("PART 7 - FragTrap hp depletion (must block attack/beRepaired at 0 hp)");
	uki.takeDamage(9999);
	uki.attack("felix");
	uki.beRepaired(10);

	separator("PART 8 - FragTrap energy depletion (100 energy points)");
	FragTrap drainy("rhumy2");
	for (int i = 0; i < 101; i++)
		drainy.attack("felix"); // 100 succeed, 101st fails: no energy
	std::cout << drainy.getName() << " energy left: " << drainy.getEnergyPoints() << std::endl;
	drainy.beRepaired(5); // must fail: no energy

	separator("PART 9 - ScavTrap copy constructor (ClapTrap copy ctor, then ScavTrap copy ctor)");
	ScavTrap fefeScav("fefe");
	fefeScav.takeDamage(30);
	ScavTrap fefeScavCopy(fefeScav);
	std::cout << fefeScavCopy.getName() << " (copy) hp:" << fefeScavCopy.getHitPoints() << std::endl;

	separator("PART 10 - FragTrap copy constructor (ClapTrap copy ctor, then FragTrap copy ctor)");
	FragTrap fefeFrag("fefe2");
	fefeFrag.takeDamage(40);
	FragTrap fefeFragCopy(fefeFrag);
	std::cout << fefeFragCopy.getName() << " (copy) hp:" << fefeFragCopy.getHitPoints() << std::endl;

	separator("PART 11 - operator= (Scav and Frag)");
	ScavTrap assignedScav;
	assignedScav = fefeScav;
	std::cout << assignedScav.getName() << " (assigned) hp:" << assignedScav.getHitPoints() << std::endl;

	FragTrap assignedFrag;
	assignedFrag = fefeFrag;
	std::cout << assignedFrag.getName() << " (assigned) hp:" << assignedFrag.getHitPoints() << std::endl;

	separator("PART 12 - Self-assignment (a = a) must not break anything");
	ScavTrap *selfPtrScav = &assignedScav;
	assignedScav = *selfPtrScav;
	FragTrap *selfPtrFrag = &assignedFrag;
	assignedFrag = *selfPtrFrag;
	std::cout << assignedScav.getName() << " still hp:" << assignedScav.getHitPoints() << std::endl;
	std::cout << assignedFrag.getName() << " still hp:" << assignedFrag.getHitPoints() << std::endl;

	separator("PART 13 - Destruction chain: ScavTrap then FragTrap (child destructor first, then ClapTrap's)");
	std::cout << "Entering a scope with a ScavTrap and a FragTrap..." << std::endl;
	{
		ScavTrap scopedScav("scopedScav");
		FragTrap scopedFrag("scopedFrag");
		scopedScav.attack("felix");
		scopedFrag.attack("felix");
	}
	std::cout << "-- back in main, both scoped objects were destroyed above --" << std::endl;

	separator("End of main, remaining objects get destroyed now");
	return (0);
}