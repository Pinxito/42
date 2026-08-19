/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:18:29 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:12:44 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor is called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &cpy) : WrongAnimal(cpy)
{
    std::cout << "WrongCat copy constructor is called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
    std::cout << "WrongCat copy assignment operator is called" << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor is called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Miaouuu je suis un WrongCat" << std::endl;
}