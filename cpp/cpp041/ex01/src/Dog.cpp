#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog constructor is called" << std::endl;
}

Dog::Dog(Dog const &cpy) : Animal(cpy), _brain(new Brain(*cpy._brain))
{
    std::cout << "Dog copy constructor is called" << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
    std::cout << "Dog copy assignment operator is called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *this->_brain = *other._brain;
    }
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor is called" << std::endl;
    delete this->_brain;
}

void Dog::makeSound(void) const
{
    std::cout << "Ouaf ouaf je suis un toutou" << std::endl;
}

Brain *Dog::getBrain(void) const
{
    return (this->_brain);
}
