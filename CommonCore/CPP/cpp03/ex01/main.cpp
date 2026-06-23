/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:09:37 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/05/25 17:34:16 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap jc("Jackie Chan");
	ClapTrap bl("Bruce Lee");

	jc.attack("Bruce Lee");
	bl.takeDamage(3);
	
	bl.beRepaired(2);

	bl.attack("Jackie Chan");
	jc.takeDamage(5);

	jc.beRepaired(3);

	std::cout << "Jackie Chan has " << jc.getHitPoints() << " hit points left." << std::endl;
	std::cout << "Bruce Lee has " << bl.getHitPoints() << " hit points left." << std::endl;

	std::cout << std::endl;
	for (int i = 0; i < 9; i++) {
		jc.attack("Bruce Lee");
		bl.takeDamage(2);
		std::cout << "Bruce Lee has " << bl.getHitPoints() << " hit points left." << std::endl;
		std::cout << "Jackie Chan has " << jc.getEnergyPoints() << " energy points left." << std::endl;
		
	}
	std::cout << std::endl;

	ScavTrap th("Thanos");
	
	th.attack("Jackie Chan");
	th.guardGate();

	std::cout << std::endl;

	return (0);
}