/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:30:27 by blevrel           #+#    #+#             */
/*   Updated: 2022/11/26 11:24:09 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class	Contact
{

public:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_nb;
	std::string	darkest_secret;
	Contact(void);
	~Contact(void);
};

#endif
