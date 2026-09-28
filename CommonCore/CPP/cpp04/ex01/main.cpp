/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:55:23 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/06/01 16:39:52 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	
	delete animal;
    delete dog;
    delete cat;

	std::cout << std::endl;
	
    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();

    delete wrong;

	std::cout << std::endl;
	
	int size = 4;
	Animal* animals[size];
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		animals[i]->makeSound();
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}
	std::cout << std::endl;

	Dog dog1;
	Dog dogcopy = dog1;
	
	dog1.getBrain()->ideas[0] = "I want to play!";
	dogcopy.getBrain()->ideas[0] = "I want to eat!";
	
	std::cout << "Dog 1 idea: " << dog1.getBrain()->ideas[0] << std::endl;
	std::cout << "Dog copy idea: " << dogcopy.getBrain()->ideas[0] << std::endl;

	std::cout << std::endl;

	Dog a;
	Dog b;
	b = a;

	std::cout << std::endl;
	
	return 0;
}