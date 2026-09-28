/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 13:00:03 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/09/14 13:09:51 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data;

	data.value = 42;

	Data *original = &data;
	
	uintptr_t serialized = Serializer::serialize(original);
	Data *deserialized = Serializer::deserialize(serialized);
	
	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Serialized value: " << serialized << std::endl;
	std::cout << "Deserialized pointer: " << deserialized << std::endl;
	std::cout << "Data value: " << deserialized->value << std::endl;
	
	if (original == deserialized)
		std::cout << "Success: The original and deserialized pointers are the same." << std::endl;
	else
		std::cout << "Error: The original and deserialized pointers are different." << std::endl;

	return (0);
}