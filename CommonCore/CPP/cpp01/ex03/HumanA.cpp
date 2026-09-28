/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:33:05 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/14 01:53:39 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : weapon(weapon) {
	this->name = name;
}
HumanA::~HumanA() {
	return;
}

void	HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}