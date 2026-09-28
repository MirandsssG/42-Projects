/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 06:01:28 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/01 07:14:49 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

int	main ()
{
	std::cout << BLUE << "\n--- Test 1: Valid Bureaucrat ---" << RESET << std::endl;
	try {
		Bureaucrat hulk("Hulk", 42);
		std::cout << GREEN << hulk << RESET << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << BLUE << "--- Test 2: Invalid Bureaucrat (Grade too high - 0) ---" << RESET << std::endl;
	try {
		Bureaucrat thanos("Thanos", 0);
		std::cout << GREEN << thanos << RESET << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- Test 3: Invalid Bureaucrat (Grade too low - 155) ---" << RESET << std::endl;
	try {
		Bureaucrat captain("Captain America", 155);
		std::cout << GREEN << captain << RESET << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- Test 4: Incrementatation ---" << RESET << std::endl;
	try {
		Bureaucrat wonder("Wonder Woman", 2);
		std::cout << GREEN << wonder << RESET << std::endl;
		wonder.incrementGrade();
		std::cout << GREEN << wonder << RESET << std::endl;
		wonder.incrementGrade();
		std::cout << GREEN << wonder << RESET << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- Test 5: Decrementation ---" << RESET << std::endl;
	try {
		Bureaucrat spider("Spider Man", 149);
		std::cout << GREEN << spider << RESET << std::endl;
		spider.decrementGrade();
		std::cout << GREEN << spider << RESET << std::endl;
		spider.decrementGrade();
		std::cout << GREEN << spider << RESET << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- Test 6: Copy constructor / Assignment operator ---" << RESET << std::endl;
	try {
		std::cout << YELLOW << "Creating Loki with grade 25" << RESET << std::endl;
		std::cout << YELLOW << "Creating Thor as a copy of Loki" << RESET << std::endl;
		std::cout << std::endl;
		Bureaucrat loki("Loki", 25);
		Bureaucrat thor(loki);
		std::cout << GREEN << thor << RESET;
		std::cout << BLUE << "'-> Copy Constructor (copies name and grade)" << RESET << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "Creating Odin with grade 1" << RESET << std::endl;
		std::cout << YELLOW << "Assigning Loki to Odin" << RESET << std::endl;
		std::cout << std::endl;
		Bureaucrat odin("Odin", 1);
		odin = loki;
		std::cout << GREEN << odin << RESET;
		std::cout << BLUE << "'-> Copy Assignment operator (copies only grade)" << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	return (0);	
}