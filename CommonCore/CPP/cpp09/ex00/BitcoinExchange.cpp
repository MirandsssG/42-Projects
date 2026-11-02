/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:58:42 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/11/02 16:34:59 by dluis-ma         ###   ########.fr       */
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

		if (end == value.c_str() || *end != '\0' || rate < 0 || !std::isfinite(rate))
			continue;
		
		_rates[date] = rate;
	}
	
	if (_rates.empty()) {
		throw std::runtime_error("Error: No valid data found in " + filename);
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	int		year;
	int		month;
	int		day;
	int		daysInMonth;
	bool	leap;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	
	for (std::string::size_type i = 0; i < date.length(); ++i)
	{
		if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}

	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return (false);

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

	if (month == 2)
		daysInMonth = leap ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		daysInMonth = 30;
	else
		daysInMonth = 31;

	return day <= daysInMonth;
}

double BitcoinExchange::parseValue(const std::string& value) const {
	std::string cleaned = trim(value);
	char *end;
	double number;

	if (cleaned.empty())
		throw std::runtime_error("Error: Empty value");
	
	errno = 0;
	number = std::strtod(cleaned.c_str(), &end);
	
	if (end == cleaned.c_str() || *end != '\0' || errno == ERANGE || !std::isfinite(number))
		throw std::runtime_error("Error: Invalid value.");

	if (number < 0)
		throw std::runtime_error("Error: not a positive number.");
	
	if (number > 1000)
		throw std::runtime_error("Error: too large a number.");
		
	return (number);
}

double BitcoinExchange::getRate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it;

	it = _rates.lower_bound(date);

	if (it != _rates.end() && it->first == date)
		return it->second;

	if (it == _rates.begin())
		throw std::runtime_error("Error: No available rate for the given date or any earlier date.");

	--it;
	return it->second;
}

void BitcoinExchange::processLine(const std::string& line) {
	std::string::size_type separator;
	std::string date;
	std::string valueText;
	double value;
	double rate;

	if (trim(line).empty())
		return;
	
	separator = line.find('|');

	if (separator == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	
	date = trim(line.substr(0, separator));
	valueText = trim(line.substr(separator + 1));
	
	if (!isValidDate(date)) {
		std::cerr << "Error: Invalid input: " << line << std::endl;
		return;
	}

	try {
		value = parseValue(valueText);
		rate = getRate(date);

		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	std::string line;
	bool firstLine = true;

	if (!file.is_open()) {
		throw std::runtime_error("Error: Could not open file " + filename);
	}

	while (std::getline(file, line)) {
		if (firstLine) {
			firstLine = false;
			if (trim(line) == "date | value") {
				continue;
			}
		}
		processLine(line);
	}

	if (file.bad())
		throw std::runtime_error("Error: I/O error while reading file " + filename);
}
