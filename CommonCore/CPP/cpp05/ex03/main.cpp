/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 06:01:28 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/08 16:10:42 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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

	Intern Ryan;
	
	std::cout << BLUE << "\n--- Test 1: Unknown Form with Intern ---" << RESET << std::endl;
	AForm* UnknownForm = Ryan.makeForm("unknown form", "Some target");
	if (UnknownForm == NULL)
		std::cout << RED << "Returned NULL succesfully" << RESET << std::endl;
		
	std::cout << BLUE << "\n--- Test 2: Robotomy Request with Intern ---" << RESET << std::endl;
	AForm* DunderMifflin = Ryan.makeForm("robotomy request", "Started the fire");
	if (DunderMifflin)
	{
		Bureaucrat Michael("Michael Scott", 1);
		Michael.signAForm(*DunderMifflin);
		Michael.executeForm(*DunderMifflin);
		delete DunderMifflin;
	}


	std::cout << BLUE << "\n--- Test 3: Shrubbery creation with Intern ---" << RESET << std::endl;
	AForm* ShrubberyForm = Ryan.makeForm("shrubbery creation", "MichaelScottPaperCompany");
	if (ShrubberyForm)
	{
		Bureaucrat Michael("Michael Scott", 1);
		Michael.signAForm(*ShrubberyForm);
		Michael.executeForm(*ShrubberyForm);

		std::ifstream file("MichaelScottPaperCompany_shrubbery");
		if (file.is_open())
		{
			std::cout << GREEN << "\nContents of MichaelScottPaperCompany_shrubbery:" << RESET << std::endl;
			std::string line;
			while (std::getline(file, line))
				std::cout << line << std::endl;
			file.close();
		}
		else
			std::cout << RED << "Error: Couldn't open MichaelScottPaperCompany_shrubbery" << RESET << std::endl;
	}
	delete ShrubberyForm;

	std::cout << BLUE << "\n--- Presidential Pardon with Intern ---" << RESET << std::endl;
	AForm* PardonForm = Ryan.makeForm("presidential pardon", "Toby Flenderson");
	if (PardonForm)
	{
		Bureaucrat Michael("Michael Scott", 1);
		Michael.signAForm(*PardonForm);
		Michael.executeForm(*PardonForm);
	}
	delete PardonForm;

	return (0);
}