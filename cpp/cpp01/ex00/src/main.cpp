/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 05:07:05 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 05:07:08 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main (void)
{
	Zombie zombie("Murielle");
	zombie.announce();

	randomChump("Yoan");

	Zombie *heapZombie = newZombie("Steve");
	heapZombie->announce();
	delete heapZombie;

	return (0);
}