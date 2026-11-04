/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:32:50 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/11/04 19:22:25 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <cerrno>
#include <cctype>
#include <utility>

PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

bool PmergeMe::isValidNumber(const std::string& str) const {
	char *end;
	long number;

	if (str.empty())
		return false;

	for (std::string::size_type i = 0; i < str.length(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}

	errno = 0;
	number = std::strtol(str.c_str(), &end, 10);

	if (errno == ERANGE || *end != '\0')
		return false;

	if (number <= 0 || number > INT_MAX)
		return false;

	return true;
}

void PmergeMe::parseInput(int ac, char **av) {
	int number;

	if (ac < 2)
		throw std::runtime_error("Error: No input numbers provided.");
	
	for (int i = 1; i < ac; i++)
	{
		if (!isValidNumber(av[i]))
			throw std::runtime_error("Error: Invalid number '" + std::string(av[i]) + "'.");

		number = std::atoi(av[i]);
		_vector.push_back(number);
		_deque.push_back(number);
		_original.push_back(number);
	}
}

void PmergeMe::displayResults() const {
	std::vector<int>::const_iterator it;

	std::cout << "Before: ";

	for (it = _original.begin(); it != _original.end(); ++it) {
		std::cout << *it;
		if (it + 1 != _original.end())
			std::cout << " ";
	}

	std::cout << std::endl;
}

static int jacobsthal(int n) {
	int previous = 0;
	int current = 1;
	int next = 0;

	if (n == 0)
		return (previous);
	if (n == 1)
		return (current);
	
	for (int i = 2; i <= n; i++) {
		next = current + 2 * previous;
		previous = current;
		current = next;
	}
	return (current);
}

int PmergeMe::binarySearchPosition(const std::vector<ChainElement>& chain, int value, int end) const {
	int left = 0;
	int right = end;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (chain[mid].value < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

std::vector<int> PmergeMe::fordJohnson(const std::vector<int>& numbers) {
	if (numbers.size() <= 1)
		return numbers;

	bool hasStraggler = (numbers.size() % 2 != 0);
	int straggler = 0;

	if (hasStraggler)
		straggler = numbers.back();

	std::vector<PairInfo> pairs;

	for (std::vector<int>::size_type i = 0; i + 1 < numbers.size(); i += 2) {
		int first = numbers[i];
		int second = numbers[i + 1];

		if (first > second)
			std::swap(first, second);

		PairInfo pair;

		pair.smaller = first;
		pair.larger = second;
		pair.id = static_cast<int>(pairs.size());

		pairs.push_back(pair);
	}

	std::vector<int> largerElements;

	for (std::vector<PairInfo>::size_type i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].larger);

	largerElements = fordJohnson(largerElements);

	std::vector<bool> used(pairs.size(), false);
	std::vector<PairInfo> sortedPairs;

	for (std::vector<int>::size_type i = 0; i < largerElements.size(); i++) {
		for (std::vector<PairInfo>::size_type j = 0; j < pairs.size(); j++) {
			if (!used[j] && pairs[j].larger == largerElements[i]) {
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	std::vector<ChainElement> mainChain;

	if (!sortedPairs.empty())
	{
	    ChainElement first;
	
	    first.value = sortedPairs[0].smaller;
	    first.pairId = sortedPairs[0].id;
	    mainChain.push_back(first);
	}

	for (std::vector<PairInfo>::size_type i = 0; i < sortedPairs.size(); i++)
	{
	    ChainElement element;
	
	    element.value = sortedPairs[i].larger;
	    element.pairId = sortedPairs[i].id;
	    mainChain.push_back(element);
	}

	std::vector<PairInfo> pending;

	for (std::vector<PairInfo>::size_type i = 1; i < sortedPairs.size(); i++)
    	pending.push_back(sortedPairs[i]);

	if (hasStraggler)
	{
		PairInfo extra;

		extra.smaller = straggler;
		extra.larger = 0;
		extra.id = -1;

		pending.push_back(extra);
	}

	for (std::vector<PairInfo>::size_type i = 0; i < pending.size(); i++) {
		int partnerIndex = -1;
		
		if (pending[i].larger != 0)
		{
			for (std::vector<ChainElement>::size_type j = 0; j < mainChain.size(); j++)
			{
				if (mainChain[j].pairId == pending[i].id) {
					partnerIndex = j;
					break;
				}
			}
		}

		if (partnerIndex == -1)
			partnerIndex = static_cast<int>(mainChain.size());
		
		int position = binarySearchPosition(mainChain, pending[i].smaller, partnerIndex);

		ChainElement element;

		element.value = pending[i].smaller;
		element.pairId = pending[i].id;
		
		mainChain.insert(mainChain.begin() + position, element);
	}

	std::vector<int> result;

	for (std::vector<ChainElement>::size_type i = 0; i < mainChain.size(); i++)
		result.push_back(mainChain[i].value);

	return (result);
}

void PmergeMe::fordJohnsonVector() {
	_vector = fordJohnson(_vector);
}