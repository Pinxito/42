/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 19:59:18 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 19:59:23 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(void)
{
	int		N = 10;
	Zombie	*horde;

	horde = zombieHorde(N, "Yoan");
	if (horde == NULL)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}