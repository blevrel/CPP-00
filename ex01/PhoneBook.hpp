/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:30:27 by blevrel           #+#    #+#             */
/*   Updated: 2022/11/26 11:31:07 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>

class	PhoneBook
{

private:
	
	std::string	fill_contact_field(std::string field_name);
	Contact	contact[8];

public:

	PhoneBook(void);
	~PhoneBook(void);
	int	size;
	void		display_summary(void);
	void		display_contact_info(int index);
	PhoneBook	add_contact(int index);
	
};

#endif
