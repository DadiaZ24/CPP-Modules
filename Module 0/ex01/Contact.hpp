/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:16:32 by ddias-fe          #+#    #+#             */
/*   Updated: 2025/02/27 15:53:45 by ddias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

enum PrintType {
	LongType,
	ShortType,
};

class Contact
{
	private:
		int	_index;
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		Contact();
		~Contact();
		void SetIndex(int index);
		void SetFirstName(std::string firstName);
		void SetLastName(std::string lastName);
		void SetNickname(std::string nickname);
		void SetPhoneNumber(std::string phoneNumber);
		void SetDarkestSecret(std::string darkestSecret);	
		void PrintIndex(PrintType type);
		void PrintFirstName(PrintType type);
		void PrintLastName(PrintType type);
		void PrintNickname(PrintType type);	
};

#endif