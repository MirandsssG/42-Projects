/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:30:11 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/08 12:57:01 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("RobotomyRequestForm", 72, 45), target(target) {
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
	: AForm(other), target(other.target) {
	
}

RobotomyRequestForm& RobotomyRequestForm:: operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	
}

void RobotomyRequestForm::execute_action() const {
	std::cout << "*** Zzzh-zzzh-zzzh ***" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << target << "." << std::endl;
}