/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:58:33 by dluis-ma          #+#    #+#             */
/*   Updated: 2026/10/22 16:02:36 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> _rates;

		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void loadRates(const std::string& filename);
		void processLine(const std::string& line);
		bool isValidDate(const std::string& date) const;
		double parseValue(const std::string& value) const;
		double getRate(const std::string& date) const;
		std::string trim(const std::string& str) const;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		void processInput(const std::string& filename);
};

#endif