/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:03:56 by smiranda          #+#    #+#             */
/*   Updated: 2025/03/03 17:12:13 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::add()
{
    if (index == 8)
    {
        std::cout << "PhoneBook full. Replacing oldest contact.\n";
        for (int i = 1; i < 8; i++)
        {
            contacts[i - 1] = contacts[i];
        }
        index  7;
    }
    std::string fName, lName, nickname, phone, secret;
    std::cout << "Enter first name: ";
    std::cin >> fName;
    std::cout << "Enter last name: ";
    std::cin >> lName;
    std::cout << "Enter nickname: ";
    std::in >> nickname;
    std::cout << "Enter phone number: ";
    std::in >> phone;
    std::cout << "Enter : ";
    std::in >> nickname;

    contacts[index].set_contact(fName, lName, phone);
    i++;
}

void PhoneBook::display_Contacts()
{
    std::cout << std::setw(10) <<
}
