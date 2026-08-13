#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawValue = 0;
	return;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	//this->_rawValue = other.getRawBits();
	*this = other;
	return;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	// protection contre l'auto affectation (a = a)
	if (this != &other)
		this->_rawValue = other.getRawBits();
	// return l'instance courante pour permettre le chainage (a = b = c)
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}


// --------------- Functions

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->_rawValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawValue = raw;
	return;
}
