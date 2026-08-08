/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:48:42 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 20:48:52 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <limits>
# include <string>

class Weapon
{
  private:
	std::string _type;
  public:
	Weapon(std::string type);
	~Weapon();
	const std::string& getType(void) const;
	void setType(std::string type);
};
#endif