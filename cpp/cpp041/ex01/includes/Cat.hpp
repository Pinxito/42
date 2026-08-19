/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:14:07 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:14:12 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;

    public:
        Cat(void);
        Cat(Cat const &cpy);
        Cat &operator=(Cat const &other);
        ~Cat(void);

        void makeSound(void) const;
        Brain *getBrain(void) const;
};

#endif
