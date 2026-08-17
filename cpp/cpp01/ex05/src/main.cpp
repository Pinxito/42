/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 01:11:05 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/18 01:11:12 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
    Harl harl;

    std::cout << std::endl << "------ DEBUG Level ------" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl << "------ INFO Level ------" << std::endl;;
    harl.complain("INFO");
    std::cout << std::endl << "------ WARNING Level ------" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl << "------ ERROR Level ------" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl << "------ No valid Level ------" << std::endl;
    harl.complain("ALARM");
    return (0);
}