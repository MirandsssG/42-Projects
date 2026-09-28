/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:05:49 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/05/25 16:29:30 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot be repaired!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
	hitPoints += amount;
	energyPoints--;
}

int ClapTrap::getHitPoints() const {
	return hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return energyPoints;
}