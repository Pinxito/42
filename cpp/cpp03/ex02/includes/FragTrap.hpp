/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 03:06:10 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 03:06:13 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
	public:
		FragTrap();
		FragTrap(const std::string &newName);
		FragTrap(const FragTrap &cpy);
		~FragTrap();
		FragTrap	&operator= (const FragTrap &rhs);
		void	highFivesGuys();
};