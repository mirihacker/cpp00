/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:55:31 by smiranda          #+#    #+#             */
/*   Updated: 2025/03/10 15:06:23 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(void) : _fName(""), _lName(""), \
_nickname(""), _phone(""), _secret("") 
{ 
    return ;
}

Contact::~Contact(void)
{
    return ;
}

void Contact::showFullContact(void) const
{
    std::cout << "First Name:       " << _fName << std::endl;
    std::cout << "Last Name:        " << _lName << std::endl;
    std::cout << "Nickname:         " << _nickname << std::endl;
    std::cout << "Phone Number:     " << _phone << std::endl;
    std::cout << "Darkest secret:   " << _secret << std::endl;
}

std::string Contact::AbbString(std::string str) const
{
    if (str.length() > 10)
        return (str.substr(0,9) + ".");
    else
        return (str);
}

void Contact::showSmallContact(void) const
{
    std::cout << std::right << std::setw(10) << AbbString(_fName) << "|" \
    << std::right << std::setw(10) << AbbString(_lName) << "|" \
    << std::right << std::setw(10) << AbbString(_nickname) << "|" << std::endl;
}

void Contact::setContact(e_Info info, const std::string& str)
{
    if (info == FIRST_NAME)
        _fName = str;
    else if (info == LAST_NAME)
        _lName = str;
    else if (info == NICKNAME)
        _nickname = str;
    else if (info == PHONE)
        _phone = str;
    else if (info == DARKEST_SECRET)
        _secret = str;
}