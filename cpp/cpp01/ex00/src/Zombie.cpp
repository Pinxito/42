/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 05:05:28 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 05:05:33 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
Zombie::Zombie(std::string name)
{
	this->_name = name;
}
Zombie::~Zombie()
{
	std::cout << this->_name << " has been killed" << std::endl;
}
void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}