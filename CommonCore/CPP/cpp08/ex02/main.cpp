/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:00:49 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/10/14 18:47:24 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
    mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;

	mstack.pop();
	
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Forward iteration:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << "Reverse iteration:" << std::endl;

	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}

	MutantStack<int> s(mstack);
	std::cout << "Copied stack top element: " << s.top() << std::endl;

	std::cout << "Comparison with list:" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
    lst.push_back(17);
	lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
	
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}

	return (0);
}