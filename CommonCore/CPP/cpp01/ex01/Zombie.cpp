/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:35:23 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/13 00:43:18 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::~Zombie() {	
	std::cout << name << " has been destroyed." << std::endl;
}

void	Zombie::setName( std::string name ) {
	this->name = name;
}

void	Zombie::announce( void ) const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
