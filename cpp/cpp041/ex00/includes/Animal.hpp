/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:12:23 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:12:09 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(std::string type);
        Animal(Animal const &cpy);
        Animal &operator=(Animal const &other);
        virtual ~Animal(void);

        std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif