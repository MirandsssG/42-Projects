/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:57:22 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/13 00:10:04 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
	this->name = name;
}

Zombie::~Zombie() {	
	std::cout << name << " has been destroyed." << std::endl;
}

void	Zombie::announce( void ) const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
