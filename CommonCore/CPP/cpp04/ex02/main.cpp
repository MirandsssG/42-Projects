/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:55:23 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/06/01 16:48:51 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	// AAnimal test;

	return (0);
}