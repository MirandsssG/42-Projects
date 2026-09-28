/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:57:27 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/13 00:09:27 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

	private:
		std::string name;

	public:
		Zombie( std::string name );
		~Zombie();
		void	announce( void ) const;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );


#endif