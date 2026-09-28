/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:12:47 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/09/15 14:14:28 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	Base *ptr;

	std::srand(std::time(NULL));
	
	ptr = generate();

	std::cout << "Identifying by pointer: " << std::endl;
	identify(ptr);

	std::cout << "Identifying by reference: " << std::endl;
	identify(*ptr);

	delete ptr;

	return (0);
}