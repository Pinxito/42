/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:14:19 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:14:22 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;

    public:
        Dog(void);
        Dog(Dog const &cpy);
        Dog &operator=(Dog const &other);
        ~Dog(void);

        void makeSound(void) const;
        Brain *getBrain(void) const;
};

#endif
