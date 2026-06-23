/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:33:19 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/14 01:53:59 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class	HumanA {
	
	private:
		std::string	name;
		Weapon		&weapon;

	public:
		HumanA( std::string name, Weapon &weapon );
		~HumanA();

		void	attack() const;
};

#endif