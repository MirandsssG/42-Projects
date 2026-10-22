/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:58:42 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/10/22 16:12:57 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <sstream>
#include <cerrno>
#include <stdexcept>
#include <cctype>
#include <cmath>

BitcoinExchange::BitcoinExchange() {
	loadRates("data.csv");
}

BitcoinExchange::~BitcoinExchange() {
}

std::string BitcoinExchange::trim(const std::string& str) const {
	std::string::size_type first;
	std::string::size_type last;

	first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";
	last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, last - first + 1);
}

void BitcoinExchange::loadRates(const std::string& filename) {
	std::ifstream file(filename.c_str());
	std::string line;
	bool firstLine = true;

	if (!file.is_open()) {
		throw std::runtime_error("Error: Could not open file " + filename);
	}

	while (std::getline(file, line)) {
		if (firstLine) {
			firstLine = false;
			if (trim(line) == "data,exchange_rate") {
				continue;
			}
		}
		if (trim(line).empty()) {
			continue;
		}
		std::string::size_type comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		
		std::string date = trim(line.substr(0, comma));
		std::string value = trim(line.substr(comma + 1));

		if (!isValidDate(date))
			continue;

		char *end;
		double rate = std::strtod(value.c_str(), &end);

		if (end == value.c_str() || *end != '\0' || rate < 0 || std::isfinite(rate))
			continue;
		
		_rates[date] = rate;
	}
	
	if (_rates.empty()) {
		throw std::runtime_error("Error: No valid data found in " + filename);
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	
}