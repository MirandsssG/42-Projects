/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:00:04 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/16 18:11:30 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <string to find> <string to replace>" << std::endl;
		return (1);
	}

	Replace replace(av[1], av[2], av[3]);

	if (!replace.replacef())
		return (1);

	return (0);
}