/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:06:05 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/10/12 16:39:48 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
	Span sp(5);
	try {
		sp.addNumber(3);
		sp.addNumber(7);
		sp.addNumber(27);
		sp.addNumber(11);
		sp.addNumber(14);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		
		sp.addNumber(20);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span large(10000);
		std::vector<int> numbers;
		int i = 0;

		while (i < 10000) {
			numbers.push_back(i * 3);
			i++;
		}
		large.addNumbers(numbers.begin(), numbers.end());

		std::cout << "Shortest Span in large: " << large.shortestSpan() << std::endl;
		std::cout << "Longest Span in large: " << large.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span small(1);
		small.addNumber(42);
		std::cout << "Shortest Span in small: " << small.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
