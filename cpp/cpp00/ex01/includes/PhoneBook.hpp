/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 22:51:30 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/07 23:10:27 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private: 
            Contact _contacts[8];
    public:
            PhoneBook(void);
            ~PhoneBook(void);
            int add(int i);
            void search(void) const;
};

#endif