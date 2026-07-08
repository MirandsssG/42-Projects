/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:29:52 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/08 13:16:36 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShruberryCreationForm", 145, 137), target(target) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other), target(other.target) {
	
}

ShrubberyCreationForm& ShrubberyCreationForm:: operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}

void ShrubberyCreationForm::execute_action() const {
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Couldn't create " << target << "_shrubbery" << std::endl;
		return;
	}
	file << "      *\n"
         << "     ***\n"
         << "    *****\n"
         << "   *******\n"
		 << "  *********\n"
         << "     |||\n";
	file.close();
}