/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:04:31 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/06 12:26:57 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) 
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) 
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form() {
	
}

const	std::string& Form::getName() const {
	return (name);
}

bool	Form::getIsSigned() const {
	return (isSigned);
}

int		Form::getGradeToSign() const {
	return (gradeToSign);
}

int		Form::getGradeToExecute() const {
	return (gradeToExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Form& form){
	os << form.getName() << ", form is signed = " << form.getIsSigned() << ", form grade to sign = " << form.getGradeToSign() << ", form grade to execute = " << form.getGradeToExecute() << std::endl;
	return (os);
}