/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:24:22 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/10/02 14:38:06 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	
	std::cout << "Searching in vector..." << std::endl;
	try {
		std::vector<int>::iterator itVec = easyfind(vec, 3);
		std::cout << "Found in vector: " << *itVec << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::vector<int>::iterator itVec = easyfind(vec, 9);
		std::cout << "Found in vector: " << *itVec << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Searching in list..." << std::endl;
	try {
		std::list<int>::iterator itLst = easyfind(lst, 20);
		std::cout << "Found in list: " << *itLst << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::list<int>::iterator itLst = easyfind(lst, 25);
		std::cout << "Found in list: " << *itLst << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}