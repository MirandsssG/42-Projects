/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:32:47 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/14 01:44:21 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) {
	this->type = type;
}

Weapon::~Weapon() {
	return;
}

const std::string& Weapon::getType() const {
	return (type);
}

void Weapon::setType( std::string newType ) {
	type = newType;
}
