/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:07:16 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/05/28 17:19:37 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
 	
 	protected:
 		std::string type;
 	public:
 		WrongAnimal();
 		WrongAnimal(const WrongAnimal &other);
 		WrongAnimal &operator=(const WrongAnimal &other);
 		~WrongAnimal();

 		void makeSound() const;
 		std::string getType() const;
};

#endif