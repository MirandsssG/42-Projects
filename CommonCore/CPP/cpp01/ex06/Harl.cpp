/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:16:27 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/16 23:45:29 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	return;
}

Harl::~Harl() {
	return;
}

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here since last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level ) {
	int	lvl = -1;

	if (level == "DEBUG")
		lvl = 0;
	else if (level == "INFO")
		lvl = 1;
	else if (level == "WARNING")
		lvl = 2;
	else if (level == "ERROR")
		lvl = 3;
	
	switch (lvl) {
		case 0:
			debug();
			/* fall through */
		case 1:
			info();
			/* fall through */
		case 2:
			warning();
			/* fall through */
		case 3:
			error();
			break;

	default:
		std::cout << "[ UNKNOWN ]" << std::endl;
		std::cout << "I don't really have a reason to complain." << std::endl;
	}
}
