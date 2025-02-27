/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:45:18 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/02/27 15:57:48 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string cmd;
	std::string index;
	
	std::cout << "Welcome to the PhoneBook!" << std::endl;
	while (1)
	{
		std::cout << "Enter one of the following commands: [ADD, SEARCH, EXIT]" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
			phoneBook.AddContact(phoneBook.GetNewContactInfo());
		else if (cmd == "SEARCH")
		{
			phoneBook.ListContacts();
		}
		else
			std::cout << "Error: Invalid command." << std::endl;
	}
	return 0;	
}
