/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 05:06:42 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 05:06:50 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
void randomChump( std::string name )
{
	Zombie new_Zombie(name);
	new_Zombie.announce();
}