/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:55:47 by smiranda          #+#    #+#             */
/*   Updated: 2025/03/10 11:09:50 by smiranda         ###   ########.fr       */
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
            std::cerr << "Please feed a single digit number." << std::endl;
        else
        {
            i = std::stoi(input);
            if (i >= 0 && i < count)
                break;
            else
            {
                if (_index == 1)
                    std::cerr << "0 is a valid index." <<std::endl;
                else if (_index >= 8)
                    std::cerr << "Valid indexes are integers between 0 and 7." << std::endl;
                else
                    std::cerr << "Current contact indexes are integers between 0 and " \
                    << (count -1) << "." << std::endl;
            }
        }
    }
    return (i);
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

int PhoneBook::searchContact(void) const
{
    int i;

    if (_index == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return (0);
    }
    displayPhonebook();
    i = getIndex();
    _contacts[i].showFullContact();
    return (0);
}

static bool isValidString(std::string input)
{
    if (input.empty())
    {
        std::cerr << "Empty string." << std::endl;
        return (false);
    }
    return (true);
}

static bool isValidPhone(std::string input)
{
    unsigned int i = 0;

    if (input.empty())
    {
        std::cerr << "Empty phone number." << std::endl;
        return (false);
    }
    if (input[0] == '+')
        i = 1;
    while (i < input.length())
    {
        if (!std::isdigit(input[i]))
        {
            if (input[i] != ' ' && input[i] != '-')
            {
                std::cerr << "Invalid phone number." << std::endl;
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
        isValid = isValidPhone(input);
    else
        isValid = isValidString(input);
    return (isValid);
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
    return (0);
}