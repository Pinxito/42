#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string.h>

class Fixed
{
	public:
		// constructor
		Fixed(void);
		// copy constructor
		Fixed(const Fixed& other);
		// copy assigment operator
		Fixed& operator=(const Fixed& other);
		// destructor
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _rawValue;
		static const int _fractionnalBits = 8;
		
};

#endif
