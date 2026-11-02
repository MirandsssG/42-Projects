/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:39:49 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/11/02 17:06:36 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <sstream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN() {
}

RPN::~RPN() {
}

bool RPN::isOperator(const std::string &token) const {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::calculate(int a, int b, char op) const {
	switch (op) {
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: Division by zero");
			return (a / b);
	}
	throw std::runtime_error("Error: Invalid operator.");
}

void RPN::processToken(const std::string &token)
{
	int	a;
	int	b;
	int	result;

	if (token.length() == 1 && token[0] >= '0' && token[0] <= '9') {
		_stack.push(token[0] - '0');
	}
	else if (isOperator(token)) {
		if (_stack.size() < 2)
			throw std::runtime_error("Error: Not enough operands.");
		b = _stack.top();
		_stack.pop();
		a = _stack.top();
		_stack.pop();
		result = calculate(a, b, token[0]);
		_stack.push(result);
	} else {
		throw std::runtime_error("Error: Invalid token.");
	}
}

int RPN::evaluate(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		processToken(token);
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error: Invalid expression.");

	return _stack.top();
}