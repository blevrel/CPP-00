/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:52:12 by blevrel           #+#    #+#             */
/*   Updated: 2022/11/26 11:08:52 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::getNbAccounts();
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";" << "created" << std::endl;
}

Account::Account(void)
{
	this->_accountIndex = Account::getNbAccounts();
	Account::_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";" << "created" << std::endl;
	return ;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "closed" << std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	time_t	ttime = time(0);

	tm	*local_time = std::localtime(&ttime);
	std::cout << "[" << 1900 + local_time->tm_year
	<< std::setfill('0') << std::setw(2) << 1 + local_time->tm_mon
	<< std::setfill('0') << std::setw(2) << local_time->tm_mday << "_"
	<< std::setfill('0') << std::setw(2) << local_time->tm_hour
	<< std::setfill('0') << std::setw(2) << local_time->tm_min
	<< std::setfill('0') << std::setw(2) << local_time->tm_sec << "] ";
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
	<< "total:" << Account::_totalAmount << ";"
	<< "deposits:" << Account::_totalNbDeposits << ";"
	<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount << ";"
	<< "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";"
	<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount << ";"
	<< "withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		Account::_totalNbWithdrawals++;;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}

int		Account::checkAmount( void ) const
{
	return(this->_amount);
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";" << "deposits:"
	<< this->_nbDeposits << ";" << "withdrawals:"
	<< this->_nbWithdrawals << std::endl;
	return ;
}
