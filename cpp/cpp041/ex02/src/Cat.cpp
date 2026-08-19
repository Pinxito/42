/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:16:13 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:16:16 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Cat constructor is called" << std::endl;
}

Cat::Cat(Cat const &cpy) : Animal(cpy), _brain(new Brain(*cpy._brain))
{
    std::cout << "Cat copy constructor is called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
    std::cout << "Cat copy assignment operator is called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *this->_brain = *other._brain;
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor is called" << std::endl;
    delete this->_brain;
}

void Cat::makeSound(void) const
{
    std::cout << "Miaouuu je suis un chat" << std::endl;
}

Brain *Cat::getBrain(void) const
{
    return (this->_brain);
}
