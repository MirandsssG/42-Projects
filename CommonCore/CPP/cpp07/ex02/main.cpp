/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:12:42 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/09/28 12:32:57 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void)
{
	std::cout << "===== Empty array =====" << std::endl;

	Array<int> empty;

	std::cout << "Size: " << empty.size() << std::endl;


	std::cout << "\n===== Integer array =====" << std::endl;

	Array<int> numbers(5);

	std::cout << "Size: " << numbers.size() << std::endl;

	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	numbers[0] = 42;
	numbers[1] = 21;

	std::cout << "After modification:" << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;


	std::cout << "\n===== Copy constructor =====" << std::endl;

	Array<int> copy(numbers);

	copy[0] = 999;

	std::cout << "Original numbers[0]: " << numbers[0] << std::endl;
	std::cout << "Copy copy[0]: " << copy[0] << std::endl;


	std::cout << "\n===== Assignment operator =====" << std::endl;

	Array<int> assigned(2);

	assigned = numbers;
	assigned[1] = 888;

	std::cout << "Original numbers[1]: " << numbers[1] << std::endl;
	std::cout << "Assigned assigned[1]: " << assigned[1] << std::endl;


	std::cout << "\n===== String array =====" << std::endl;

	Array<std::string> strings(3);

	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "42";

	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << strings[i] << std::endl;


	std::cout << "\n===== Out of bounds =====" << std::endl;

	try
	{
		std::cout << numbers[5] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: index out of bounds" << std::endl;
	}

	try
	{
		std::cout << numbers[100] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: index out of bounds" << std::endl;
	}

	return (0);
}