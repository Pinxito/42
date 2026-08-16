#include "Fixed.hpp"
#include <iostream>
#include <istream>

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

// ------------- Ajout pour l'ex01

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	// decale les bits vers la gauche <=> a multiplier par 2^8
	this->_rawValue = n << this->_fractionnalBits;
	return;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	// Pas possible de faire de decalage de bits sur un float
	// -> Multiplie par 2^8 puis arrondi avec roundf()
	this->_rawValue = roundf(f * (1 << this->_fractionnalBits));
	return;
}

// ------------- operator ex02
bool Fixed::operator>(const Fixed& other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}
	
Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(void)
{
	this->_rawValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this); // save current state
	this->_rawValue++; // incremente
	return (tmp); // return state befor incrementation
}

Fixed& Fixed::operator--(void)
{
	this->_rawValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_rawValue--;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

// --------------- Functions ex00

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_rawValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawValue = raw;
	return;
}

// --------------- Functions ex01

int Fixed::toInt(void) const
{
	// operation inverse : decalage des bits vers la droit pour avoir un int
	return this->_rawValue >> this->_fractionnalBits;
}

float Fixed::toFloat(void) const
{
	// on divise la valeur brute par 2^8 (casté en float pour conserver la virgule)
	return ((float)this->_rawValue / (float)(1 << this->_fractionnalBits));
}

// ----------- Surchage de l'operator d'insertion

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	// on insere en float du nb a virgule fixe dans le flux
	out << fixed.toFloat();
	return (out);
}
