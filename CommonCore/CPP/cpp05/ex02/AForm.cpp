/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:04:31 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/06 12:26:57 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute) 
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) 
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm() {
	
}

const	std::string& AForm::getName() const {
	return (name);
}

bool	AForm::getIsSigned() const {
	return (isSigned);
}

int		AForm::getGradeToSign() const {
	return (gradeToSign);
}

int		AForm::getGradeToExecute() const {
	return (gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm){
	os << AForm.getName() << ", AForm is signed = " << AForm.getIsSigned() << ", AForm grade to sign = " << AForm.getGradeToSign() << ", AForm grade to execute = " << AForm.getGradeToExecute() << std::endl;
	return (os);
}