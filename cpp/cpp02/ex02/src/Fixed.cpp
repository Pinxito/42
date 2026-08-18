/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 07:49:34 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/18 11:25:12 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	// Utilise l'opérateur d'affectation pour copier l'objet.
	*this = other;
	return;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	// Évite une copie inutile en cas d'auto-affectation.
	if (this != &other)
		this->_rawValue = other.getRawBits();

	// Permet les affectations en chaîne : a = b = c.
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

//Constructeurs pour l'ex01

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;

	// Convertit l'entier en nombre à virgule fixe.
	// Décaler de 8 bits revient à multiplier par 2^8.
	this->_rawValue = n << this->_fractionnalBits;
	return;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;

	// Convertit le float en virgule fixe puis arrondit
	// le résultat avant de le stocker sous forme d'entier.
	this->_rawValue = roundf(f * (1 << this->_fractionnalBits));
	return;
}

//Opérateurs de comparaison

bool Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

//Opérateurs arithmétiques 

Fixed Fixed::operator+(const Fixed& other) const
{
	// Convertit les deux valeurs, effectue l'opération
	// puis crée un nouvel objet Fixed avec le résultat.
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

//Opérateurs d'incrémentation et de décrémentation

Fixed& Fixed::operator++(void)
{
	// Pré-incrémentation : modifie l'objet avant de le retourner.
	this->_rawValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	// Post-incrémentation : conserve la valeur avant modification.
	Fixed	tmp(*this);

	this->_rawValue++;
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	// Pré-décrémentation : modifie l'objet avant de le retourner.
	this->_rawValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	// Post-décrémentation : conserve la valeur avant modification.
	Fixed	tmp(*this);

	this->_rawValue--;
	return (tmp);
}

//Fonctions min / max

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	// Retourne une référence vers l'objet ayant la plus petite valeur.
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	// Version utilisable avec des objets constants.
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	// Retourne une référence vers l'objet ayant la plus grande valeur.
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	// Version utilisable avec des objets constants.
	return (a > b ? a : b);
}

// Fonctions liées à la valeur brute

int	Fixed::getRawBits(void) const
{
	return (this->_rawValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawValue = raw;
	return;
}

// ---------- Fonctions de conversion ----------

int Fixed::toInt(void) const
{
	// Supprime les bits réservés à la partie fractionnaire.
	// C'est l'opération inverse effectuée lors de la conversion d'un int.
	return (this->_rawValue >> this->_fractionnalBits);
}

float Fixed::toFloat(void) const
{
	// Retrouve la valeur réelle en divisant par 2^8.
	return ((float)this->_rawValue
		/ (float)(1 << this->_fractionnalBits));
}

//Opérateur d'insertion dans un flux

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	// Affiche la valeur réelle plutôt que la valeur brute stockée.
	out << fixed.toFloat();
	return (out);
}