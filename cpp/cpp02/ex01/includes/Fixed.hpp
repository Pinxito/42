/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:58:03 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/12 20:35:59 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed {
	private:
			int		_nb;
			static const int  _fracBits = 8;
	public:
			Fixed(void);
			Fixed(const int nb);
			Fixed(const float nb);
			~Fixed(void);
			Fixed(Fixed const &Fixed);
			Fixed& operator=(Fixed const &Fixed);
			int getRawBits( void ) const;
			void setRawBits( int const raw );
			float toFloat( void ) const;
			int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& o, Fixed const& f);

#endif