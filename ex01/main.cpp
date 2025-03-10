/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:12:58 by smiranda          #+#    #+#             */
/*   Updated: 2025/03/10 11:07:41 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook MyPhoneBook;
    std::string command;

    while (true)
    {
        std::cin.clear();
        std::cout << "Enter a command: ";
        std::cin >> std::ws;
        std::getline(std::cin, command);
        if (std::cin.eof() || command == "EXIT")
            return (0);
        else if (command == "ADD")
        {
            if (MyPhoneBook.addContact())
                std::cerr << "Failed to add a new contact." << std::endl;
        }
        else if (command == "SEARCH")
            MyPhoneBook.searchContact();
        else
            std::cerr << "Valid commands are ADD, SEARCH and EXIT." << std::endl;
    }
    return (0);
}