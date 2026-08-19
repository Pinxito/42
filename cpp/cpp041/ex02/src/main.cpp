/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:16:36 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:16:39 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

static void separator(std::string const &title)
{
    std::cout << std::endl;
    std::cout << "========== " << title << " ==========" << std::endl;
}

int main(void)
{
    /*
     * Animal animal;
     *
     * Uncommenting the line above must NOT compile because Animal is abstract:
     * Animal::makeSound() is pure virtual.
     */

    separator("ABSTRACT BASE / POLYMORPHISM");
    Animal *animals[10];

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    separator("DEEP COPY STILL WORKS");
    Dog originalDog;
    originalDog.getBrain()->setIdeas("Original dog idea", 0);
    Dog copiedDog(originalDog);
    copiedDog.getBrain()->setIdeas("Copy changed independently", 0);

    std::cout << "Original: " << originalDog.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Copy:     " << copiedDog.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Different Brain addresses: "
              << (originalDog.getBrain() != copiedDog.getBrain()) << std::endl;

    separator("COPY ASSIGNMENT STILL WORKS");
    Cat originalCat;
    originalCat.getBrain()->setIdeas("Original cat idea", 0);
    Cat assignedCat;
    assignedCat = originalCat;
    assignedCat.getBrain()->setIdeas("Assignment changed independently", 0);

    std::cout << "Original: " << originalCat.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Assigned: " << assignedCat.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Different Brain addresses: "
              << (originalCat.getBrain() != assignedCat.getBrain()) << std::endl;

    separator("VIRTUAL DESTRUCTION");
    for (int i = 0; i < 10; i++)
        delete animals[i];

    return (0);
}
