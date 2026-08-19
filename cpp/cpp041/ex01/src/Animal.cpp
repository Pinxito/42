#include "../includes/Animal.hpp"

Animal::Animal(void) : type("")
{
    std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal constructor with type is called" << std::endl;
}

Animal::Animal(Animal const &cpy) : type(cpy.type)
{
    std::cout << "Animal copy constructor is called" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
    std::cout << "Animal copy assignment operator is called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor is called" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound" << std::endl;
}
