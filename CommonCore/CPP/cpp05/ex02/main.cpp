/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 06:01:28 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/08 16:08:40 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

int	main ()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Bureaucrat highGrade("Thanos", 1);
	Bureaucrat lowGrade("Peter Parker", 150);
	
	ShrubberyCreationForm shrubberyForm("42Campus");
	RobotomyRequestForm robotomyForm("Tony Stark");
	PresidentialPardonForm pardonForm("Itachi");

	std::cout << BLUE << "\n--- Test 1: Testing execute with High Grade but not signed yet ---" << RESET << std::endl;
	highGrade.executeForm(shrubberyForm);

	std::cout << BLUE << "\n--- Test 2: Signed form and then executing with High Grade in Shrubbery Creation Form---" << RESET << std::endl;
	highGrade.signAForm(shrubberyForm);
	highGrade.executeForm(shrubberyForm);
	std::ifstream file("42Campus_shrubbery");
	if (file.is_open())
	{
		std::cout << GREEN << "\nContents of 42Campus_shrubbery:" << RESET << std::endl;
		std::string line;
		while (std::getline(file, line))
			std::cout << line << std::endl;
		file.close();
	}
	else
	{
		std::cerr << RED << "Error: Couldn't open 42Campus_shrubbery" << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- Test 3: Testing execute with signed form but Low Grade ---" << RESET << std::endl;
	lowGrade.signAForm(robotomyForm);
	lowGrade.executeForm(robotomyForm);

	std::cout << BLUE << "\n--- Test 4: Testing Robotomy Request Form (5 times, random 50/50) ---" << RESET << std::endl;
	highGrade.signAForm(robotomyForm);
	for (int i = 0; i < 5; i++)
		highGrade.executeForm(robotomyForm);

	std::cout << BLUE << "\n--- Test 5: Testing Presidential Pardon Form ---" << RESET << std::endl;
	highGrade.signAForm(pardonForm);
	highGrade.executeForm(pardonForm);

	return (0);
}