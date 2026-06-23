/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:32:54 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/14 01:46:36 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
	
	private:
		std::string type;

	public:
		Weapon( std::string type );
		~Weapon();
		const std::string& getType() const;
		void setType( std::string newType );
};

#endif