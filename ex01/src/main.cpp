/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:12:58 by smiranda          #+#    #+#             */
/*   Updated: 2025/03/10 15:54:39 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int main(void)
{
    PhoneBook MyPhoneBook;
    std::string command;

    while (true)
    {
        std::cin.clear();
        std::cout << "\033[1;37mEnter a command: \033[0m";
        std::cin >> std::ws;
        std::getline(std::cin, command);
        if (std::cin.eof() || command == "EXIT")
            return (0);
        else if (command == "ADD")
        {
            if (MyPhoneBook.addContact())
                std::cerr << "\033[1;31mFailed to add a new contact.\033[0m" << std::endl;
        }
        else if (command == "SEARCH")
            MyPhoneBook.searchContact();
        else
            std::cerr << "\033[1;31mValid commands are ADD, SEARCH and EXIT.\033[0m" << std::endl;
    }
    return (0);
}
