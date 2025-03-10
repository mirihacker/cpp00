/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:21:03 by smiranda          #+#    #+#             */
/*   Updated: 2025/03/10 16:31:13 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>
# include <iomanip>

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        int addContact();
        int searchContact(void) const;

    private:
        void displayPhonebook() const;
        unsigned int getIndex(void) const;
        static const unsigned int _maxContact = 8;
        Contact _contacts[_maxContact];
        unsigned int _contactNext;
        unsigned int _index;
};

#endif