/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:07:32 by smiranda          #+#    #+#             */
/*   Updated: 2025/03/10 11:03:42 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

enum e_Info
{
    FIRST_NAME,
    LAST_NAME,
    NICKNAME,
    PHONE,
    DARKEST_SECRET,
    END
};

class Contact
{
    public:
    Contact(void);
    ~Contact(void);
    void setContact(e_Info info, const std::string& str);
    void showSmallContact() const;
    void showFullContact() const;
    
    private:
        std::string AbbString(std::string str) const;
        std::string _fName;
        std::string _lName;
        std::string _nickname;
        std::string _phone;
        std::string _secret;
};

#endif