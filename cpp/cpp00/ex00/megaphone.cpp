/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 22:13:22 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/07 22:14:56 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int    main(int ac, char **av)
{
    int    i;

    i = 1;
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (av[i])
        {
            
            
            std::string word(av[i]);
            for (std::string::size_type j = 0; j < word.size(); j++)
            word[j] = std::toupper(static_cast<unsigned char>(word[j]));
            std::cout << word;
            i++;
        }
        std::cout << std::endl;
    }
    
    return (0);
}