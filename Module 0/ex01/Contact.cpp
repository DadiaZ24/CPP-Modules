/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:17:31 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/02/27 15:44:24 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::SetIndex(int index)
{
	_index = index;
}

void Contact::SetFirstName(std::string firstName)
{
	_firstName = firstName;
}

void Contact::SetLastName(std::string lastName)
{
	_lastName = lastName;
}

void Contact::SetNickname(std::string nickname)
{
	_nickname = nickname;
}

void Contact::SetPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Contact::SetDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
}

void Contact::PrintIndex(PrintType type)
{
	if (type == ShortType)
		std::cout << std::setw(10) << _index << " | ";
	else
		std::cout << _index << std::endl;
}

void Contact::PrintFirstName(PrintType type)
{
	if (type == ShortType)
		std::cout << std::setw(10) << _firstName << " | ";
	else
		std::cout << _firstName << std::endl;
}

void Contact::PrintLastName(PrintType type)
{
	if (type == ShortType)
		std::cout << std::setw(10) << _lastName << " | ";
	else
		std::cout << _lastName << std::endl;
}

void Contact::PrintNickname(PrintType type)
{
	if (type == ShortType)
		std::cout << std::setw(10) << _nickname << std::endl;
	else
		std::cout << _nickname << std::endl;
}
