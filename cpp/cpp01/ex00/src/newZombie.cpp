/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 05:05:59 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 05:06:18 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Zombie.hpp"
Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}