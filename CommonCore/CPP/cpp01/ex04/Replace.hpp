/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:00:15 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/16 18:11:49 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

class Replace {
	
	private:
		std::string filename;
		std::string s1;
		std::string s2;

	public:
		Replace(std::string filename, std::string s1, std::string s2);
		~Replace();

		bool	replacef();
};

#endif