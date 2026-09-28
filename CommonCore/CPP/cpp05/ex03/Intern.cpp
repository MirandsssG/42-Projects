/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:47:45 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/08 14:10:24 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

Intern::Intern() {

}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {

}

static AForm* createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	typedef AForm* (*FormCreator)(const std::string&);

	struct FormMapping {
		std::string name;
		FormCreator creator;
	};

	static const FormMapping forms[] = {
		{"shrubbery creation", createShrubberyCreationForm},
		{"robotomy request", createRobotomyRequestForm},
		{"presidential pardon", createPresidentialPardonForm}
	};

	static const size_t numForms = sizeof(forms) / sizeof(forms[0]);

	for (size_t i = 0; i < numForms; i++) {
		if (forms[i].name == formName) {
			AForm* form = forms[i].creator(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cerr << "Intern couldn't create form: " << formName << std::endl;
	return (NULL);
}