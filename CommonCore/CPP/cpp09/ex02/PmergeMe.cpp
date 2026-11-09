/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:32:50 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/11/09 10:05:00 by dluis-ma         ###   ########.fr       */
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

PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0) {
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
	std::cout << "After using std::vector: ";

	for (it = _vector.begin(); it != _vector.end(); ++it) {
		std::cout << *it;
		if (it + 1 != _vector.end())
			std::cout << " ";
	}

	std::cout << std::endl;
	std::cout << "After using std::deque: ";

	for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it) {
		std::cout << *it;
		if (it + 1 != _deque.end())
			std::cout << " ";
	}

	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << _vectorTime << " us" << std::endl;

	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << _dequeTime << " us" << std::endl;
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

int PmergeMe::binarySearchPosition(const std::deque<ChainElement>& chain, int value, int end) const {
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

std::vector<int> PmergeMe::getInsertionOrder(int size) const {
	std::vector<int> order;
	int previous = 1;
	int current = 3;
	int next;
	int start;

	while (previous <= size) {
		start = current - 2;

		if (start >= size)
			start = size - 1;

		for (int i = start; i >= previous - 1; i--)
			order.push_back(i);
		
		next = current + 2 * previous;
		previous = current;
		current = next;
	}
	return (order);
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

	std::vector<int> insertionOrder = getInsertionOrder(static_cast<int>(pending.size()));

	for (std::vector<PairInfo>::size_type i = 0; i < insertionOrder.size(); i++) {
		int partnerIndex = -1;
		int index = insertionOrder[i];
		
		if (pending[index].id != -1)
		{
			for (std::vector<ChainElement>::size_type j = 0; j < mainChain.size(); j++)
			{
				if (mainChain[j].pairId == pending[index].id) {
					partnerIndex = j;
					break;
				}
			}
		}

		if (partnerIndex == -1)
			partnerIndex = static_cast<int>(mainChain.size());
		
		int position = binarySearchPosition(mainChain, pending[index].smaller, partnerIndex);

		ChainElement element;

		element.value = pending[index].smaller;
		element.pairId = pending[index].id;
		
		mainChain.insert(mainChain.begin() + position, element);
	}

	std::vector<int> result;

	for (std::vector<ChainElement>::size_type i = 0; i < mainChain.size(); i++)
		result.push_back(mainChain[i].value);

	return (result);
}

std::deque<int> PmergeMe::fordJohnson(const std::deque<int>& numbers) {
	if (numbers.size() <= 1)
		return numbers;
	
	bool hasStraggler = (numbers.size() % 2 != 0);
	int straggler = 0;

	if (hasStraggler)
		straggler = numbers.back();
	
	std::deque<PairInfo> pairs;

	for (std::deque<int>::size_type i = 0; i + 1 < numbers.size(); i += 2) {
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

	std::deque<int> largerElements;

	for (std::deque<PairInfo>::size_type i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].larger);
	
	largerElements = fordJohnson(largerElements);

	std::deque<bool> used(pairs.size(), false);
	std::deque<PairInfo> sortedPairs;

	for (std::deque<int>::size_type i = 0; i < largerElements.size(); i++) {
		for (std::deque<PairInfo>::size_type j = 0; j < pairs.size(); j++) {
			if (!used[j] && pairs[j].larger == largerElements[i]) {
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	std::deque<ChainElement> mainChain;

	if (!sortedPairs.empty())
	{
	    ChainElement first;
	
	    first.value = sortedPairs[0].smaller;
	    first.pairId = sortedPairs[0].id;
	    mainChain.push_back(first);
	}

	for (std::deque<PairInfo>::size_type i = 0; i < sortedPairs.size(); i++)
	{
	    ChainElement element;
	
	    element.value = sortedPairs[i].larger;
	    element.pairId = sortedPairs[i].id;
	    mainChain.push_back(element);
	}

	std::deque<PairInfo> pending;

	for (std::deque<PairInfo>::size_type i = 1; i < sortedPairs.size(); i++)
		pending.push_back(sortedPairs[i]);
	
	if (hasStraggler)
	{
		PairInfo extra;

		extra.smaller = straggler;
		extra.larger = 0;
		extra.id = -1;

		pending.push_back(extra);
	}

	std::vector<int> insertionOrder = getInsertionOrder(static_cast<int>(pending.size()));

	for (std::vector<int>::size_type i = 0; i < insertionOrder.size(); i++) {
		int partnerIndex = -1;
		int index = insertionOrder[i];
		
		if (pending[index].id != -1)
		{
			for (std::deque<ChainElement>::size_type j = 0; j < mainChain.size(); j++)
			{
				if (mainChain[j].pairId == pending[index].id) {
					partnerIndex = j;
					break;
				}
			}
		}

		if (partnerIndex == -1)
			partnerIndex = static_cast<int>(mainChain.size());
		
		int position = binarySearchPosition(mainChain, pending[index].smaller, partnerIndex);

		ChainElement element;

		element.value = pending[index].smaller;
		element.pairId = pending[index].id;
		
		mainChain.insert(mainChain.begin() + position, element);
	}

	std::deque<int> result;

	for (std::deque<ChainElement>::size_type i = 0; i < mainChain.size(); i++)
		result.push_back(mainChain[i].value);
	
	return (result);
}

void PmergeMe::fordJohnsonVector() {
	_vector = fordJohnson(_vector);
}

void PmergeMe::fordJohnsonDeque() {
	_deque = fordJohnson(_deque);
}

void PmergeMe::execute() {
	clock_t start;
	clock_t end;

	start = clock();
	fordJohnsonVector();
	end = clock();

	_vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	fordJohnsonDeque();
	end = clock();

	_dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}