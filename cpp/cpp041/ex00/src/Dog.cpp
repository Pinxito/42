/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:17:32 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:12:35 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog constructor is called" << std::endl;
}

Dog::Dog(Dog const &cpy) : Animal(cpy)
{
    std::cout << "Dog copy constructor is called" << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
    std::cout << "Dog copy assignment operator is called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor is called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Ouaf ouaf je suis un toutou" << std::endl;
}