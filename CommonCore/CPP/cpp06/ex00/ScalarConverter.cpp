/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:01:20 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/09/14 13:07:07 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum StrType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

static StrType getType(const std::string& str) 
{
	if (str.size() == 1 && !std::isdigit(str[0]))
		return CHAR;
	if (str == "nan" || str == "+inf" || str == "-inf")
		return DOUBLE;
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return FLOAT;
	
	bool hasDecimal = false;
	bool hasF = false;
	bool hasDigit = false;
	size_t i = 0;
	
	if (str.empty())
		return INVALID;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (i >= str.size())
		return INVALID;
	
	for (; i < str.size(); i++)
	{
		if (str[i] == '.')
		{
			if (hasDecimal)
				return INVALID;
			hasDecimal = true;
		}
		else if (str[i] == 'f' && i == str.size() - 1)
			hasF = true;
		else if (std::isdigit(str[i]))
			hasDigit = true;
		else
			return INVALID;		
	}
	if (!hasDigit)
		return INVALID;
	if (hasF)
		return FLOAT;
	if (hasDecimal)
		return DOUBLE;
	return INT;
}

static void printChar(double num)
{
	if (std::isnan(num) || std::isinf(num) || num < CHAR_MIN || num > CHAR_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(num);
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printInt(double num)
{
	if (std::isnan(num) || std::isinf(num) || num < INT_MIN || num > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
}

static void printFloat(double num)
{
	std::cout << "float: ";
	if (std::isnan(num))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(num))
		std::cout << (num > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		float f = static_cast<float>(num);
		std::cout << f;
		if (std::fmod(f, 1.0f) == 0.0f)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

static void printDouble(double num)
{
	std::cout << "double: ";
	if (std::isnan(num))
		std::cout << "nan" << std::endl;
	else if (std::isinf(num))
		std::cout << (num > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << num;
		if (std::fmod(num, 1.0) == 0.0)
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	StrType type = getType(literal);
	double value = 0;
	
	switch (type)
	{
		case CHAR:
		{
			value = static_cast<double>(literal[0]);
			break;
		}
		case INT:
		{
			char *end;
			long l = std::strtol(literal.c_str(), &end, 10);
			if (*end != '\0' || l < INT_MIN || l > INT_MAX)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
			value = static_cast<double>(l);
			break;
		}
		case FLOAT:
		{
			char *end;
			float f = std::strtof(literal.c_str(), &end);
			if (*end != '\0')
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
			value = static_cast<double>(f);
			break;
		}
		case DOUBLE:
		{
			char *end;
			value = std::strtod(literal.c_str(), &end);
			if (*end != '\0')
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
			break;
		}
		case INVALID:
		default:
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}