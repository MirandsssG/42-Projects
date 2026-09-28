/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:03:40 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/09/28 11:06:42 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T &min(const T &a, const T &b) {
	if (a < b)
		return a;
	return b;
}

template <typename T>
const T &max(const T &a, const T &b) {
	if (a > b)
		return a;
	return b;
}

#endif