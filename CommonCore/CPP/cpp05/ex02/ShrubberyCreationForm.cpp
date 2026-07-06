/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:29:52 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/06 16:21:19 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShruberryCreationForm", 145, 137), target(target) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other), target(other.target) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) {
	if (this != other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}

void ShrubberyCreationForm::draw_tree() const {
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Couldn't create " << target << "_shrubbery" << std::endl;
		return;
	}
	// tree
}