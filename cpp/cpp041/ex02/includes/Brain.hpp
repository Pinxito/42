/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:15:16 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/19 17:15:21 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain(void);
        Brain(Brain const &cpy);
        Brain &operator=(Brain const &other);
        ~Brain(void);

        std::string getIdeas(int index) const;
        void setIdeas(std::string const &idea, int index);
};

#endif
