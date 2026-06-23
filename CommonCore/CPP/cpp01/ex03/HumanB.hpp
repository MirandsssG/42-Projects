/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:33:26 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/14 01:59:20 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class	HumanB {
	
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		HumanB( std::string name );
		~HumanB();

		void	setWeapon( Weapon &weapon );
		void	attack() const;
};

#endif