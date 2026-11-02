/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:39:42 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/11/02 16:42:47 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <stack>
# include <string>
# include <iostream>

class RPN {

	private:
		std::stack<int> _stack;
		
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		bool isOperator(const std::string &token) const;
		int calculate(int a, int b, char op) const;
		void processToken(const std::string &token);

	public:
		RPN();
		~RPN();

		int evaluate(const std::string &expression);
};

#endif