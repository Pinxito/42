/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 05:03:32 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 05:03:55 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>
class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);
		~Zombie();
		void announce( void );
};
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
#endif