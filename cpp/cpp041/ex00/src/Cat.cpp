/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:17:19 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:12:31 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat constructor is called" << std::endl;
}

Cat::Cat(Cat const &cpy) : Animal(cpy)
{
    std::cout << "Cat copy constructor is called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
    std::cout << "Cat copy assignment operator is called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor is called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Miaouuu je suis un chat" << std::endl;
}