/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:15:40 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/02/27 15:58:32 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int contactCount;
		Contact contacts[8];
		void GetContact(int index);
	public:
		PhoneBook();
		~PhoneBook();
		Contact GetNewContactInfo();
		void AddContact(Contact contact);
		void ListContacts();
	};

#endif