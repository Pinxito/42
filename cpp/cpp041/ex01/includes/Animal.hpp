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
