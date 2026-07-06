/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 06:01:28 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/07/06 12:43:24 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

int	main ()
{
	std::cout << BLUE << "\n--- Test 1: Valid Bureaucrat ---" << RESET << std::endl;
	try {
		Bureaucrat hulk("Hulk", 42);
		std::cout << GREEN << hulk << RESET << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << BLUE << "--- Test 2: Invalid Bureaucrat (Grade too high - 0) ---" << RESET << std::endl;
	try {
		Bureaucrat thanos("Thanos", 0);
		std::cout << GREEN << thanos << RESET << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- Test 3: Invalid Bureaucrat (Grade too low - 155) ---" << RESET << std::endl;
	try {
		Bureaucrat captain("Captain America", 155);
		std::cout << GREEN << captain << RESET << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- Test 4: Incrementatation ---" << RESET << std::endl;
	try {
		Bureaucrat wonder("Wonder Woman", 2);
		std::cout << GREEN << wonder << RESET << std::endl;
		wonder.incrementGrade();
		std::cout << GREEN << wonder << RESET << std::endl;
		wonder.incrementGrade();
		std::cout << GREEN << wonder << RESET << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- Test 5: Decrementation ---" << RESET << std::endl;
	try {
		Bureaucrat spider("Spider Man", 149);
		std::cout << GREEN << spider << RESET << std::endl;
		spider.decrementGrade();
		std::cout << GREEN << spider << RESET << std::endl;
		spider.decrementGrade();
		std::cout << GREEN << spider << RESET << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- Test 6: Copy constructor / Assignment operator ---" << RESET << std::endl;
	try {
		std::cout << YELLOW << "Creating Loki with grade 25" << RESET << std::endl;
		std::cout << YELLOW << "Creating Thor as a copy of Loki" << RESET << std::endl;
		std::cout << std::endl;
		Bureaucrat loki("Loki", 25);
		Bureaucrat thor(loki);
		std::cout << GREEN << thor << RESET;
		std::cout << BLUE << "'-> Copy Constructor (copies name and grade)" << RESET << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW << "Creating Odin with grade 1" << RESET << std::endl;
		std::cout << YELLOW << "Assigning Loki to Odin" << RESET << std::endl;
		std::cout << std::endl;
		Bureaucrat odin("Odin", 1);
		odin = loki;
		std::cout << GREEN << odin << RESET;
		std::cout << BLUE << "'-> Copy Assignment operator (copies only grade)" << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << BLUE << "\n\n--- Test 7: Valid Form ---" << RESET << std::endl;
	try {
		Form test1 ("Test 1", 50, 50);
		std::cout << GREEN << test1 << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << BLUE << "--- Test 8: Invalid Form (grade to sign too high) ---" << RESET << std::endl;
	try {
		Form test2 ("Test 2", 0, 50);
		std::cout << GREEN << test2 << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << BLUE << "--- Test 9: Invalid Form (grade to sign too low) ---" << RESET << std::endl;
	try {
		Form test3 ("Test 3", 200, 50);
		std::cout << GREEN << test3 << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << BLUE << "--- Test 10: Invalid Form (grade to execute too high) ---" << RESET << std::endl;
	try {
		Form test4 ("Test 4", 50, 0);
		std::cout << GREEN << test4 << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << BLUE << "--- Test 11: Invalid Form (grade to execute too low) ---" << RESET << std::endl;
	try {
		Form test5 ("Test 5", 50, 200);
		std::cout << GREEN << test5 << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << BLUE << "--- Test 12: Form is Signed starts at false ---" << RESET << std::endl;
	try {
		Form test6 ("Test 6", 50, 50);
		std::cout << GREEN << test6 << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << BLUE << "--- Test 13: Copy constructor Form ---" << RESET << std::endl;
	try {
		Form test7 ("Test 7", 50, 50);
		std::cout << GREEN << test7 << RESET << std::endl;
		Form test8 (test7);
		std::cout << GREEN << test8 << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "--- Test 14: Copy assignment operator Form (only isSigned should change) ---" << RESET << std::endl;
	try {
		Form test9 ("Test 9", 50, 50);
		std::cout << GREEN << test9 << RESET << std::endl;
		Form test10 ("Test 10", 100, 100);
		std::cout << GREEN << test10 << RESET << std::endl;
		test10 = test9;
		std::cout << GREEN << test10 << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	return (0);	
}