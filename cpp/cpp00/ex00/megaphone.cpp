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

int    main(int ac, char **av)
{
    int    i;
    int    j;

    i = 1;
    j = 0;
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (av[i])
        {
            j = 0;
            while (av[i][j])
            {
                std::cout << (char)std::toupper(av[i][j]);
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}