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

		// comparison operator
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// arithmetics operator
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

/*
La différence entre pré et post-incrémentation :
En C++, pour différencier ++a (pré-incrémentation) de a++ (post-incrémentation)
lors de la surcharge, la norme veut que l'on ajoute un paramètre int factice
dans la déclaration de la version post-incrémentée (Fixed operator++(int);).

Le compilateur comprendra ainsi automatiquement laquelle appeler.
De plus, la pré-incrémentation retourne une référence (Fixed&) car
elle modifie et renvoie l'objet lui-même, tandis que la post-incrémentation
retourne une copie (Fixed) de l'objet avant sa modification.

De plus, la pré-incrémentation retourne une référence (Fixed&)
car elle modifie et renvoie l'objet lui-même,
tandis que la post-incrémentation retourne une copie (Fixed)
de l'objet avant sa modification.
 */

		//incrementation & decrementation operator
		Fixed& operator++(void); // ++a
		Fixed operator++(int); // a++
		Fixed& operator--(void); // --a
		Fixed operator--(int); // a--

/*
Les fonctions static : Les fonctions min et max
sont déclarées comme static, ce qui signifie qu'elles appartiennent
à la classe elle-même et non à une instance

Car pour min et max : leur rôle n'est pas d'agir sur elles-mêmes,
mais de se contenter de comparer deux références d'objets Fixed fournies en paramètres
*/
		// Functions static min & max
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

	private:
		int _rawValue;
		static const int _fractionnalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
