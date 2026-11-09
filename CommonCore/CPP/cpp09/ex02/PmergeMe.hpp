/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:32:57 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/11/09 10:14:38 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <string>
# include <vector>
# include <deque>
# include <iostream>
# include <utility>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		std::vector<int> _original;
		
		double _vectorTime;
		double _dequeTime;

		void fordJohnsonVector();
		void fordJohnsonDeque();

		bool isValidNumber(const std::string& str) const;

		std::vector<int> fordJohnson(const std::vector<int>& numbers);

		std::deque<int> fordJohnson(const std::deque<int>& numbers);
		
		struct PairInfo {
			int smaller;
			int larger;
			int id;
		};

		struct ChainElement {
		    int value;
		    int pairId;
		};

		int binarySearchPosition(const std::vector<ChainElement>& chain, int value, int end) const;

		int binarySearchPosition(const std::deque<ChainElement>& chain, int value, int end) const;

		std::vector<int> getInsertionOrder(int size) const;


	public:
		PmergeMe();
		~PmergeMe();

		void parseInput(int ac, char **av);
		void execute();
		void displayResults() const;
};

#endif