/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:30:40 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/08 20:32:08 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iomanip>
# include <iostream>
#include <string>
int main (void)
{
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;
	std::cout << "Adress of the string: " << &s << std::endl;
	std::cout << "Adress of the Pointeur: " << stringPTR << std::endl;
    std::cout << "Adress of the reference: " << &stringREF << std::endl << std::endl;
	std::cout << "Value of the string: " << s << std::endl;
	std::cout << "Value of the Pointeur: " << *stringPTR << std::endl;
    std::cout << "Value of the reference: " << stringREF << std::endl;
}