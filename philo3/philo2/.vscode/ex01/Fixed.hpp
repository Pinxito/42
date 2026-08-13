#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed(void);

		Fixed(int const n);
		Fixed(float const f);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
	private:
		int _rawValue;
		static const int _fractionnalBits = 8;
};

/*
La surcharge d'opérateur :
Ca permet de redéfinir le comportement d'un opérateur existant (ici <<)
pour qu'il sache comment interagir avec nos propres classes.

Le sujet de l'exercice exige l'ajout d'une surcharge de l'opérateur d'insertion (<<)
qui insère une représentation en virgule flottante du nombre à virgule fixe
dans l'objet de flux de sortie passé en paramètre.
*/

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
