/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:30:14 by blevrel           #+#    #+#             */
/*   Updated: 2022/11/26 11:30:53 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include <cstdlib>

int	check_cmd(const std::string& command)
{
	if (command.compare("ADD") == 0)
		return (0);
	if (command.compare("SEARCH") == 0)
		return (1);
	if (command.compare("EXIT") == 0)
		exit(0);
	return (-1);
}

int	verif_index_value(PhoneBook book, int book_index_int, std::string book_index_str)
{
	if (book_index_str.size() != 1 || book_index_int < 1)
		std::cout << "Invalid index" << std::endl;
	else if (book_index_int > book.size)
		std::cout << "No contact at index " << book_index_int << std::endl << std::endl;
	else
		return (1);
	return (0);
}

void	cmd_is_search(PhoneBook book)
{
	int			book_index_int;
	int			trigger;
	std::string	book_index_str;

	trigger = 1;
	if (book.size == 0)
	{
		std::cout << "No contacts in PhoneBook" << std::endl << std::endl;
		return ;
	}
	book.display_summary();
	while (trigger)
	{
		std::cout << "Enter contact index for detailed information" << std::endl;
		std::getline(std::cin, book_index_str);
		if (!std::cin)
			return ;
		if (book_index_str.empty())
			continue ;
		book_index_int = std::atoi(book_index_str.c_str());
		if (verif_index_value(book, book_index_int, book_index_str))
			trigger = 0;
	}
	book.display_contact_info(book_index_int - 1);
}

void	read_from_cin()
{
	std::string	command;
	PhoneBook	book;
	int	index = 0;
	int			cmd;

	while (std::cin)
	{
		std::cout << "What do you want to do ?" << std::endl;
		std::getline(std::cin, command);
		if (!std::cin)
			return ;
		cmd = check_cmd(command);
		if (cmd == -1)
			std::cout << "The program only accepts ADD, SEARCH and EXIT." << std::endl << std::endl;
		else if (cmd == 0)
		{
			book.add_contact(index);
			index++;
		}
		else
			cmd_is_search(book);
		if (index == 8)
			index = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Program takes no arguments" << std::endl;
		return (1);
	}
	read_from_cin();
	return (0);
}
