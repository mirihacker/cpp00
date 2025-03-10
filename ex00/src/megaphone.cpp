/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:34:33 by smiranda          #+#    #+#             */
/*   Updated: 2025/02/26 17:52:57 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    j = 0;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE NOISE *" << std::endl;
        return (0);
    }
    while (argv[++j])
    {
        i = 0;
        while(argv[j][i])
        {
            std::cout << (char)toupper(argv[j][i]);
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}