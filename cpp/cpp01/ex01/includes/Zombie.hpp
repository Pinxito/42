/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 05:15:20 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 20:00:16 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iomanip>
# include <iostream>
# include <limits>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(void);
	~Zombie(void);
	void announce(void);
	void setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif