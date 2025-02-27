/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:14:54 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/02/27 16:00:37 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contactCount = 0;
}

PhoneBook::~PhoneBook()
{
}

Contact PhoneBook::GetNewContactInfo()
{
	Contact contact;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Enter the first name: " << std::endl;
	std::getline(std::cin, firstName);
	std::cout << "Enter the last name: " << std::endl;
	std::getline(std::cin, lastName);
	std::cout << "Enter the nickname: " << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Enter the phone number: " << std::endl;
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter the darkest secret: " << std::endl;
	std::getline(std::cin, darkestSecret);
	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Error: All fields must be filled." << std::endl;
		return GetNewContactInfo();
	}
	contact.SetIndex(contactCount);
	contact.SetFirstName(firstName);
	contact.SetLastName(lastName);
	contact.SetNickname(nickname);
	contact.SetPhoneNumber(phoneNumber);
	contact.SetDarkestSecret(darkestSecret);
	return contact;	
}

void PhoneBook::AddContact(Contact contact)
{
	if (contactCount <= 8)
		contactCount = 0;
	contacts[contactCount] = contact;
	contactCount++;
}

void PhoneBook::ListContacts()
{
	std::string index;
	
	if (contactCount == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactCount; i++)
	{
		contacts[i].PrintIndex(ShortType);
		contacts[i].PrintFirstName(ShortType);
		contacts[i].PrintLastName(ShortType);
		contacts[i].PrintNickname(ShortType);
	}
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, index);
	if (index.length() != 1 || index[0] < '0' || index[0] > '7')
		std::cout << "Error: Invalid index." << std::endl;
	else
		GetContact(index[0] - '0');
}

void PhoneBook::GetContact(int index)
{
	if (index < 0 || index >= contactCount)
	{
		std::cout << "Error: Invalid index." << std::endl;
		return;
	}
	contacts[index].PrintFirstName(LongType);
	contacts[index].PrintLastName(LongType);
	contacts[index].PrintNickname(LongType);
}
