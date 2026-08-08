/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:56:29 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 20:56:46 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>
# include "Weapon.hpp"

class HumanB
{
  private:
	std::string _name;
	Weapon 		*_weapon;
  public:
	HumanB(std::string name);
	~HumanB(void);
	void attack() const;
	void setWeapon(Weapon &weapon);
};
#endif