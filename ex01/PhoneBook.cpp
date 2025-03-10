/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:55:47 by smiranda          #+#    #+#             */
/*   Updated: 2025/03/10 14:43:33 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactNext(0), _index(0) 
{
    return ;
}

PhoneBook::~PhoneBook(void) 
{
    return ;
}

void PhoneBook::displayPhonebook(void) const
{
    unsigned int i = 0;
    unsigned int count = 0;
    
    std::cout << "|" << std::right << std::setw(10) << "Index" << "|" \
    << std::right << std::setw(10) << "First Name" << "|" \
    << std::right << std::setw(10) << "Last Name" << "|" \
    << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
    
    if (_index >= 8)
    count = 8;
    else
    count = _index;
    while (i < count)
    {
        std::cout << "|";
        std::cout <<std::right << std::setw(10) << i << "|";
        _contacts[i].showSmallContact();
        i++;
    }
}

unsigned int PhoneBook::getIndex(void) const
{
    std::string input;
    unsigned int i;
    unsigned int count = (_index > 8) ? 8 : _index;

    while (true)
    {
        std::cin.clear();
        std::cout << "Enter contact index: ";
        std::cin >> std::ws;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(1);
        if (input.empty() || !std::isdigit(input[0]))
            std::cerr << "\033[1;31mPlease feed a single digit number.\033[0m" << std::endl;
        else
        {
            i = std::stoi(input);
            if (i >= 0 && i < count)
                break;
            else
            {
                if (_index >= 8)
                    std::cerr << "\033[1;31mValid indexes are integers between 0 and 7.\033[0m" << std::endl;
                else
                    std::cerr << "\033[1;31mCurrent contact indexes are integers between 0 and " \
                    << (count -1) << ".\033[0m" << std::endl;
            }
        }
    }
    return (i);
}

int PhoneBook::searchContact(void) const
{
    int i;
    
    if (_index == 0)
    {
        std::cout << "\033[1;37mPhoneBook is empty.\033[0m" << std::endl;
        return (0);
    }
    displayPhonebook();
    i = getIndex();
    _contacts[i].showFullContact();
    return (0);
}


static void storeInput(e_Info info, std::string& input)
{
    switch (info)
    {
        case FIRST_NAME:
        std::cout << "Enter first name: ";
        break;
        case LAST_NAME:
        std::cout << "Enter last name: ";
        break;
        case NICKNAME:
        std::cout << "Enter nickname: ";
        break;
        case PHONE:
        std::cout << "Enter phone number: ";
        break;
        case DARKEST_SECRET:
        std::cout << "Enter darkest secret: ";
        break;
        case END:
        break;
    }
    std::getline(std::cin >> std::ws, input);
    return ;
}

static bool validPhone(std::string input)
{
    unsigned int i = 0;

    if (input[0] == '+')
        i = 1;
    while (i < input.length())
    {
        if (!std::isdigit(input[i]))
        {
            if (input[i] != ' ' && input[i] != '-')
            {
                std::cerr << "\033[1;31mInvalid phone number.\033[0m" << std::endl;
                return (false);
            }
        }
        i++;
    }
    return (true);
}

static bool isValidInput(e_Info info, std::string input)
{
    bool isValid;
    
    if (std::cin.eof())
        exit(1);
    if (info == PHONE)
        isValid = validPhone(input);
    else
        isValid = true;
    return (isValid);
}

int PhoneBook::addContact()
{
    Contact contact;
    std::string input;
    
    for (e_Info info = FIRST_NAME; info < END; info = static_cast<e_Info>(info + 1))
    {
        storeInput(info, input);
        if (isValidInput(info, input) == false)
            return (1);
        contact.setContact(info, input);
    }
    _contacts[_contactNext] = contact;
    _index += 1;
    _contactNext = _index % _maxContact;
    std::cout << "\033[1;32mContact added succesfully!\033[0m" << std::endl;
    return (0);
}