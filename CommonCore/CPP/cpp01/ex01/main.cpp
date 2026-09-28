/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:35:16 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/13 00:47:47 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* horde = zombieHorde(8, "Walker");
	for (int i = 0; i < 8; i++)
		horde[i].announce();
	delete[] horde;
}
