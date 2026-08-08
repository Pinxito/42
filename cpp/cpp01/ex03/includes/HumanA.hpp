/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:53:41 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 20:53:47 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>
# include "Weapon.hpp"

class HumanA
{
  private:
	std::string _name;
	Weapon 		&_weapon;
  public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void attack() const;
};
#endif