/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:47:58 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/12 23:40:18 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {
	return;
}

Contact::~Contact( void ) {	
	return;
}

static	std::string truncate(const std::string& str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

bool	only_letters(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isalpha(str[i]))
			return (false);
	return (true);
}

bool	only_numbers(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

void	Contact::input_contact() {
	while (true)
	{
		std::cout << "Enter first name: ";
		if (!std::getline(std::cin, first_name))
		{
			std::cout << std::endl << "EOF detected. Exiting." << std::endl;
			exit (1);
		}
		if (!first_name.empty() && only_letters(first_name))
			break;
		std::cout << "Invalid input. First name must contain only letters and must not be empty." << std::endl;
	}
	while (true)
	{
		std::cout << "Enter last name: ";
		if (!std::getline(std::cin, last_name))
		{
			std::cout << std::endl << "EOF detected. Exiting." << std::endl;
			exit (1);
		}
		if (!last_name.empty() && only_letters(last_name))
			break;
		std::cout << "Invalid input. Last name must contain only letters and must not be empty." << std::endl;
	}
	while (true)
	{
		std::cout << "Enter nickname: ";
		if (!std::getline(std::cin, nickname))
		{
			std::cout << std::endl << "EOF detected. Exiting." << std::endl;
			exit (1);
		}
		if (!nickname.empty() && only_letters(nickname))
			break;
		std::cout << "Invalid input. Nickname must contain only letters and must not be empty." << std::endl;
	}
	while (true)
	{
		std::cout << "Enter phone numbers: ";
		if (!std::getline(std::cin, phone_number))
		{
			std::cout << std::endl << "EOF detected. Exiting." << std::endl;
			exit (1);
		}
		if (!phone_number.empty() && only_numbers(phone_number))
			break;
		std::cout << "Invalid input. Phone number must contain only numbers and must not be empty." << std::endl;
	}
	while (true)
	{
		std::cout << "Enter darkest secret: ";
		if (!std::getline(std::cin, darkest_secret))
		{
			std::cout << std::endl << "EOF detected. Exiting." << std::endl;
			exit (1);
		}
		if (!darkest_secret.empty())
			break;
	}
}

void	Contact::display_short(int index) const {
	std::cout << std::setw(10) << index << "|"
			  << std::setw(10) << truncate(first_name) << "|"
			  << std::setw(10) << truncate(last_name) << "|"
			  << std::setw(10) << truncate(nickname) << std::endl;
}

void	Contact::display_full() const {
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}