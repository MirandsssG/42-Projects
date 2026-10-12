/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:05:50 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/10/12 15:18:41 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : _maxSize(n), _numbers() {
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {
}

void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize)
		throw std::length_error("Cannot add more numbers, Span is full");
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
	std::vector<int> sorted;
	unsigned int shortest;
	unsigned int diff;
	std::vector<int>::size_type i;

	if (_numbers.size() < 2)
		throw std::length_error("Not enough numbers to find a span");
	sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	shortest = static_cast<unsigned int>(static_cast<long long>(sorted[1]) - static_cast<long long>(sorted[0]));
	i = 1;
	while (i < sorted.size() - 1) {
		diff = static_cast<unsigned int>(static_cast<long long>(sorted[i + 1]) - static_cast<long long>(sorted[i]));
		if (diff < shortest)
			shortest = diff;
		++i;
	}
	return (shortest);
}

unsigned int Span::longestSpan() const {
	std::vector <int>::const_iterator minIt;
	std::vector <int>::const_iterator maxIt;

	if (_numbers.size() < 2)
		throw std::length_error("Not enough numbers to find a span");
	minIt = std::min_element(_numbers.begin(), _numbers.end());
	maxIt = std::max_element(_numbers.begin(), _numbers.end());
	return(static_cast<unsigned int>(static_cast<long long>(*maxIt) - static_cast<long long>(*minIt)));
}
