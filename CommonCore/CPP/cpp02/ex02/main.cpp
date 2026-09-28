/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:09:37 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/06/24 11:31:15 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;	
}

// int	main( void ) {
// 	std::cout << "===== Constructors =====" << std::endl;

// 	Fixed a;
// 	Fixed b(10);
// 	Fixed c(42.42f);
// 	Fixed d(b);

// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	std::cout << "c = " << c << std::endl;
// 	std::cout << "d = " << d << std::endl;

// 	std::cout << "\n===== Assignment =====" << std::endl;

// 	a = c;

// 	std::cout << "a = c" << std::endl;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "c = " << c << std::endl;

// 	std::cout << "\n===== Conversion =====" << std::endl;

// 	std::cout << "c as float = " << c.toFloat() << std::endl;
// 	std::cout << "c as int   = " << c.toInt() << std::endl;

// 	std::cout << "\n===== Comparisons =====" << std::endl;

// 	Fixed x(5.5f);
// 	Fixed y(2.25f);

// 	std::cout << "x = " << x << std::endl;
// 	std::cout << "y = " << y << std::endl;

// 	std::cout << "x > y  : " << (x > y) << std::endl;
// 	std::cout << "x < y  : " << (x < y) << std::endl;
// 	std::cout << "x >= y : " << (x >= y) << std::endl;
// 	std::cout << "x <= y : " << (x <= y) << std::endl;
// 	std::cout << "x == y : " << (x == y) << std::endl;
// 	std::cout << "x != y : " << (x != y) << std::endl;

// 	std::cout << "\n===== Arithmetic =====" << std::endl;

// 	std::cout << "x + y = " << (x + y) << std::endl;
// 	std::cout << "x - y = " << (x - y) << std::endl;
// 	std::cout << "x * y = " << (x * y) << std::endl;
// 	std::cout << "x / y = " << (x / y) << std::endl;

// 	std::cout << "\n===== Increment / Decrement =====" << std::endl;

// 	Fixed n;

// 	std::cout << "n        = " << n << std::endl;
// 	std::cout << "++n      = " << ++n << std::endl;
// 	std::cout << "n        = " << n << std::endl;

// 	std::cout << "n++      = " << n++ << std::endl;
// 	std::cout << "n        = " << n << std::endl;

// 	std::cout << "--n      = " << --n << std::endl;
// 	std::cout << "n        = " << n << std::endl;

// 	std::cout << "n--      = " << n-- << std::endl;
// 	std::cout << "n        = " << n << std::endl;

// 	std::cout << "\n===== min / max =====" << std::endl;

// 	Fixed p(12.75f);
// 	Fixed q(12.50f);

// 	std::cout << "p = " << p << std::endl;
// 	std::cout << "q = " << q << std::endl;

// 	std::cout << "min(p, q) = " << Fixed::min(p, q) << std::endl;
// 	std::cout << "max(p, q) = " << Fixed::max(p, q) << std::endl;

// 	const Fixed r(100.1f);
// 	const Fixed s(99.9f);

// 	std::cout << std::endl;
// 	std::cout << "r = " << r << std::endl;
// 	std::cout << "s = " << s << std::endl;

// 	std::cout << "min(r, s) = " << Fixed::min(r, s) << std::endl;
// 	std::cout << "max(r, s) = " << Fixed::max(r, s) << std::endl;

// 	std::cout << "\n===== Chained Operations =====" << std::endl;

// 	Fixed result = ((Fixed(5.05f) * Fixed(2)) + Fixed(1.5f))
// 		/ Fixed(3);

// 	std::cout << "((5.05 * 2) + 1.5) / 3 = "
// 			  << result << std::endl;

// 	std::cout << "\n===== Precision Test =====" << std::endl;

// 	Fixed small(0.00390625f);

// 	std::cout << "small = " << small << std::endl;

// 	++small;

// 	std::cout << "after ++small = "
// 			  << small << std::endl;

// 	return 0;
// }