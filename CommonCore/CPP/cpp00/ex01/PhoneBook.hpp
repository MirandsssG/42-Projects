/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:47:45 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/12 12:23:11 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

class PhoneBook {

private:
	Contact	contacts[8];
	int		index;
	int		count;

public:
	PhoneBook( void );
	~PhoneBook( void );
	void	show_instructions() const;
	void	add_contacts();
	void	search_contacts() const;

};

#endif