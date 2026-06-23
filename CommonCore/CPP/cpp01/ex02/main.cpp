/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:23:51 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/14 01:30:28 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	
	std::string*	strPTR = &str;
	std::string&	strREF = str;
	
	std::cout << "Memory address of str:        " << &str << std::endl;
	std::cout << "Memory address of strPTR:     " << strPTR << std::endl;
	std::cout << "Memory address of strREF:     " << &strREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of str:                 " << str << std::endl;
	std::cout << "Value pointed to by strPTR:   " << *strPTR << std::endl;
	std::cout << "Value referred to by strREF:  " << strREF << std::endl;

	return (0);
}
