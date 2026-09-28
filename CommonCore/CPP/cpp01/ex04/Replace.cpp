/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:00:09 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/16 22:53:10 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2) {
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
}

Replace::~Replace() {
	return;
}

bool	Replace::replacef() {
	if (s1.empty())
	{
		std::cerr << "Error: string to find cannot be empty" << std::endl;
		return (false);
	}
	
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: could not open file " << std::endl;
		return (false);
	}
	
	std::ofstream outfile((filename + ".replace").c_str());
	{
		if (!outfile)
		{
			std::cerr << "Error: could not create output file" << std::endl;
			return (false);
		}
	}

	std::string	line;
	while (std::getline(infile, line))
	{
		size_t	pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line;
		if (!infile.eof())
			outfile << std::endl;
	}

	infile.close();
	outfile.close();
	return (true);
}
