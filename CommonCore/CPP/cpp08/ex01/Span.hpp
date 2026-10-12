/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:06:00 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/10/12 15:12:09 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
	public:
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
	
		void addNumber(int number);
		
		template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end) {
			unsigned int count = 0;
			InputIterator it = begin;
			
			while (it != end) {
				++count;
				++it;
			}
			if (count > _maxSize - _numbers.size())
				throw std::length_error("Adding these numbers would exceed the maximum size of the Span");
			_numbers.insert(_numbers.end(), begin, end);
		}

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif