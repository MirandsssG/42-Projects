/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:09:59 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/05/21 17:32:31 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fp_value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fp_value = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int value) {
	// std::cout << "Int constructor called" << std::endl;
	this->fp_value = value << fractional_bits;
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructor called" << std::endl;
	this->fp_value = roundf(value * (1 << fractional_bits));
}

float Fixed::toFloat(void) const {
	return (float)this->fp_value / (1 << fractional_bits);
}

int Fixed::toInt(void) const {
	return this->fp_value >> fractional_bits;
}

int Fixed::getRawBits(void) const {
	return this->fp_value;
}

void Fixed::setRawBits(int const raw) {
	this->fp_value = raw;
}


bool Fixed::operator>(const Fixed &other) const {
	return this->fp_value > other.fp_value;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->fp_value < other.fp_value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->fp_value >= other.fp_value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->fp_value <= other.fp_value;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->fp_value == other.fp_value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->fp_value != other.fp_value;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(fp_value + other.fp_value);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(fp_value - other.fp_value);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((fp_value * other.fp_value) >> fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result.setRawBits((fp_value << fractional_bits) / other.fp_value);
	return result;
}

Fixed &Fixed::operator++() {
	fp_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	fp_value++;
	return temp;
}

Fixed &Fixed::operator--() {
	fp_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	fp_value--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}