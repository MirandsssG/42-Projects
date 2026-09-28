/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:47:53 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/12 12:17:32 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	bool		exit = false;
	std::string	input;

	std::cout << "Welcome to My Awesome Phonebook" << std::endl;
	while (!exit)
	{
		phonebook.show_instructions();
		if (!std::getline(std::cin, input))
		{
			std::cout << "EOF detected. Exiting." << std::endl;
			exit = true;
			continue;
		}
		else if (input == "ADD")
			phonebook.add_contacts();
		else if (input == "SEARCH")
			phonebook.search_contacts();
		else if (input == "EXIT")
		{
			std::cout << "Exiting My Awesome Phonebook. Goodbye!" << std::endl;
			exit = true;
			continue;
		}
		else if (!input.empty())
			std::cout << "Invalid command: " << input << std::endl;
	}

	return (0);
}
