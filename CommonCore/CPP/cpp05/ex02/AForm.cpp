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

void	AForm::execute(Bureaucrat const & executor) const {
	if (!isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
	execute_action();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& form){
	os	<< "AForm: " << form.getName()
		<< ", AForm is signed = " << form.getIsSigned()
		<< ", AForm grade to sign = " << form.getGradeToSign()
		<< ", AForm grade to execute = " << form.getGradeToExecute() << std::endl;
	return (os);
}