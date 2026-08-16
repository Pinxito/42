/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 20:00:19 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/12 20:36:30 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Fixed constructor called" << std::endl;
	this->_nb = 0;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Default constructor called" << std::endl;
	this->_nb = nb << Fixed::_fracBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_nb = roundf(nb * (1 << Fixed::_fracBits));
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(other);
}

Fixed& Fixed::operator=(Fixed const& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_nb = src.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_nb);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_nb / (1 << Fixed::_fracBits));
}

int Fixed::toInt(void) const
{
	return (this->_nb >> Fixed::_fracBits);
}

std::ostream& operator<<(std::ostream& o, Fixed const& f)
{
	o << f.toFloat();
	return (o);
}