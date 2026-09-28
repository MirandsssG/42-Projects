/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:15:56 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/09/28 11:25:33 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T &element) {
	std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T &element) {
	element++;
}

int main(void)
{
	// Test with an array of integers
	
	int intArray[] = {1, 2, 3, 4, 5};
	
	std::cout << "Original intArray:" << std::endl;
	iter(intArray, 5, printElement<int>);

	std::cout << std::endl;
	std::cout << "Incrementing intArray..." << std::endl;
	iter(intArray, 5, incrementElement<int>);
	std::cout << std::endl;

	std::cout << "After increment:" << std::endl;
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	// Test with an array of strings

	std::string stringArray[] = {"Hello", "World", "42", "School"};
	
	std::cout << "Original stringArray:" << std::endl;
	iter(stringArray, 4, printElement<std::string>);
	std::cout << std::endl;
	
	// Test with an array of const integers
	
	const int constArray[] = {10, 20, 30, 40, 50};
	
	std::cout << "Original constArray:" << std::endl;
	iter(constArray, 5, printElement<int>);
	
	return (0);
}