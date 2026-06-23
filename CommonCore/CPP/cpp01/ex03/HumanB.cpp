/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:33:11 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/14 01:59:25 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) {
	this->name = name;
	weapon = NULL;
}

HumanB::~HumanB() {
	return;
}

void	HumanB::setWeapon( Weapon &weapon ) {
	this->weapon = &weapon;
}

void	HumanB::attack() const {
	if (weapon)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
}
