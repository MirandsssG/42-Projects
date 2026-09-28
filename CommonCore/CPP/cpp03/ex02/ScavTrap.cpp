/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:18:19 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/06/24 11:42:33 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " cannot attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ScavTrap::guardGate() {
	if (this->hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead and cannot enter Gate keeper mode." << std::endl;
		return;
	}
	if (this->guardMode)
	{
		std::cout << "ScavTrap " << this->name << " is already in Gate keeper mode." << std::endl;
		return;
	}
	this->guardMode = true;
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}