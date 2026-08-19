/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:15:58 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:16:02 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain constructor is called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "";
}

Brain::Brain(Brain const &cpy)
{
    std::cout << "Brain copy constructor is called" << std::endl;
    *this = cpy;
}

Brain &Brain::operator=(Brain const &other)
{
    std::cout << "Brain copy assignment operator is called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor is called" << std::endl;
}

std::string Brain::getIdeas(int index) const
{
    if (index >= 0 && index < 100)
        return (this->_ideas[index]);
    return ("");
}

void Brain::setIdeas(std::string const &idea, int index)
{
    if (index >= 0 && index < 100)
        this->_ideas[index] = idea;
}
