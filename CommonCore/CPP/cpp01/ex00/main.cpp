/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:57:14 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/13 00:27:03 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* hZombie = newZombie("HZombie");
	hZombie->announce();
	delete hZombie;

	randomChump("SZombie");
}
