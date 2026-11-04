/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:32:57 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/11/04 19:19:24 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <utility>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		std::vector<int> _original;

		void sortVector();
		void sortDeque();

		void fordJohnsonVector();
		void fordJohnsonDeque();

		void insertPendingVector();
		void insertPendingDeque();

		bool isValidNumber(const std::string& str) const;

		std::vector<int> fordJohnson(const std::vector<int>& numbers);
		
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


	public:
		PmergeMe();
		~PmergeMe();

		void parseInput(int ac, char **av);
		void execute();
		void displayResults() const;
};

#endif