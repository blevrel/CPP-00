/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:32:38 by blevrel           #+#    #+#             */
/*   Updated: 2022/11/26 11:31:52 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	this->size = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "All contacts destroyed" << std::endl;
	return ;
}

std::string	trim_copy(std::string cpy)
{
	if (cpy.length() > 10)
	{
		cpy.resize(9);
		cpy.resize(10, '.');
	}
	return (cpy);
}

void	PhoneBook::display_summary(void)
{
	int			i;
	std::string	cpy;

	i = 0;
	if (this->size)
	{
		std::cout << "***********************************************" << std::endl;
		std::cout << "**     INDEX|FIRST NAME| LAST NAME|  NICKNAME**" << std::endl;
		std::cout << "***********************************************" << std::endl;
	}
	while (i < this->size)
	{
		std::cout << std::right << std::setw(12) << i + 1 << "|";
		cpy = this->contact[i].first_name;
		cpy = trim_copy(cpy);
		std::cout << std::right << std::setw(10) << cpy << "|";
		cpy = this->contact[i].last_name;
		cpy = trim_copy(cpy);
		std::cout << std::right << std::setw(10) << cpy << "|";
		cpy = this->contact[i].nickname;
		cpy = trim_copy(cpy);
		std::cout << std::right << std::setw(10) << cpy << "|" << std::endl;
		i++;
	}
}

void	PhoneBook::display_contact_info(int index)
{
	std::cout << "Last name: "<< this->contact[index].last_name << std::endl << std::endl;
	std::cout << "First name: " << this->contact[index].first_name << std::endl << std::endl;
	std::cout << "Nickname: " << this->contact[index].nickname << std::endl << std::endl;
	std::cout << "Phone number: " << this->contact[index].phone_nb << std::endl << std::endl;
	std::cout << "Darkest secret: " << this->contact[index].darkest_secret << std::endl << std::endl;

}

std::string	PhoneBook::fill_contact_field(std::string field_name)
{
	std::string	check_value;
	
	std::cout << "Enter contact " << field_name << std::endl;
	std::getline(std::cin, check_value);
	if (check_value.empty() || check_value.find_first_not_of("\t\n\v\f\r ") == std::string::npos)
			std::cout << "Value can not be empty or space" << std::endl;
	while (std::cin && (check_value.empty() || check_value.find_first_not_of("\t\n\v\f\r ") == std::string::npos))
	{
		std::cout << "Enter contact " << field_name << std::endl;
		std::getline(std::cin, check_value);
		if (check_value.empty() || check_value.find_first_not_of("\t\n\v\f\r ") == std::string::npos)
			std::cout << "Value can not be empty or space" << std::endl;
	}
	return (check_value);
}

PhoneBook	PhoneBook::add_contact(int index)
{
	int			i;

	i = 0;
	while (std::cin && i < 5)
	{
		if (i == 0)
			this->contact[index].last_name = fill_contact_field("last name");
		if (i == 1)
			this->contact[index].first_name = fill_contact_field("first name");
		if (i == 2)
			this->contact[index].nickname = fill_contact_field("nickname");
		if (i == 3)
			this->contact[index].phone_nb = fill_contact_field("phone number");
		if (i == 4)
			this->contact[index].darkest_secret = fill_contact_field("darkest secret");
		i++;
	}
	if (this->size < 8)
		this->size++;
	return (*this);
}
