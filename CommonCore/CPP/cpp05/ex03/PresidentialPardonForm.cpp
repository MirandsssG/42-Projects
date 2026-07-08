/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:30:27 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/08 12:56:57 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("PresidentialPardonForm", 25, 5), target(target) {
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other), target(other.target) {
	
}

PresidentialPardonForm& PresidentialPardonForm:: operator=(const PresidentialPardonForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	
}

void PresidentialPardonForm::execute_action() const {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}