/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:18:53 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:12:38 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

static void printSeparator(const std::string &title)
{
    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================" << std::endl;
}

int main(void)
{
    printSeparator("1. BASIC POLYMORPHISM");

    const Animal *meta = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    std::cout << "Animal type: " << meta->getType() << std::endl;

    std::cout << std::endl;
    std::cout << "Dog sound: ";
    dog->makeSound();

    std::cout << "Cat sound: ";
    cat->makeSound();

    std::cout << "Animal sound: ";
    meta->makeSound();


    printSeparator("2. VIRTUAL DESTRUCTOR");

    std::cout << "Deleting Animal:" << std::endl;
    delete meta;

    std::cout << std::endl;
    std::cout << "Deleting Dog through Animal pointer:" << std::endl;
    delete dog;

    std::cout << std::endl;
    std::cout << "Deleting Cat through Animal pointer:" << std::endl;
    delete cat;


    printSeparator("3. WRONG POLYMORPHISM");

    const WrongAnimal *wrongAnimal = new WrongAnimal();
    const WrongAnimal *wrongCatAsAnimal = new WrongCat();

    std::cout << "WrongAnimal type: "
              << wrongAnimal->getType() << std::endl;

    std::cout << "WrongCat type through WrongAnimal pointer: "
              << wrongCatAsAnimal->getType() << std::endl;

    std::cout << std::endl;

    std::cout << "WrongAnimal sound: ";
    wrongAnimal->makeSound();

    std::cout << "WrongCat through WrongAnimal pointer: ";
    wrongCatAsAnimal->makeSound();

    std::cout << std::endl;
    std::cout << "Expected: both calls use WrongAnimal::makeSound()"
              << std::endl;


    printSeparator("4. DIRECT WRONGCAT");

    WrongCat directWrongCat;

    std::cout << "Direct WrongCat type: "
              << directWrongCat.getType() << std::endl;

    std::cout << "Direct WrongCat sound: ";
    directWrongCat.makeSound();

    std::cout << std::endl;
    std::cout << "Expected: direct WrongCat uses WrongCat::makeSound()"
              << std::endl;


    printSeparator("5. WRONG DESTRUCTION");

    std::cout << "Deleting WrongAnimal:" << std::endl;
    delete wrongAnimal;

    std::cout << std::endl;
    std::cout << "Deleting WrongCat through WrongAnimal pointer:"
              << std::endl;
    delete wrongCatAsAnimal;


    printSeparator("6. DOG COPY CONSTRUCTOR");

    Dog dogOriginal;

    std::cout << "Original type: "
              << dogOriginal.getType() << std::endl;

    Dog dogCopy(dogOriginal);

    std::cout << "Copied type: "
              << dogCopy.getType() << std::endl;

    std::cout << "Copied Dog sound: ";
    dogCopy.makeSound();


    printSeparator("7. DOG COPY ASSIGNMENT");

    Dog dogAssigned;

    dogAssigned = dogOriginal;

    std::cout << "Assigned type: "
              << dogAssigned.getType() << std::endl;

    std::cout << "Assigned Dog sound: ";
    dogAssigned.makeSound();


    printSeparator("8. CAT COPY CONSTRUCTOR");

    Cat catOriginal;

    std::cout << "Original type: "
              << catOriginal.getType() << std::endl;

    Cat catCopy(catOriginal);

    std::cout << "Copied type: "
              << catCopy.getType() << std::endl;

    std::cout << "Copied Cat sound: ";
    catCopy.makeSound();


    printSeparator("9. CAT COPY ASSIGNMENT");

    Cat catAssigned;

    catAssigned = catOriginal;

    std::cout << "Assigned type: "
              << catAssigned.getType() << std::endl;

    std::cout << "Assigned Cat sound: ";
    catAssigned.makeSound();


    printSeparator("10. POLYMORPHISM WITH STACK OBJECTS");

    Dog stackDog;
    Cat stackCat;

    Animal *animalDog = &stackDog;
    Animal *animalCat = &stackCat;

    std::cout << "Animal pointer -> Dog: ";
    animalDog->makeSound();

    std::cout << "Animal pointer -> Cat: ";
    animalCat->makeSound();


    printSeparator("END OF MAIN");

    std::cout << "Local objects will now be destroyed automatically."
              << std::endl;

    return (0);
}
