/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitcoin.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:26 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/17 00:21:09 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitcoin.hpp"

Bitcoin::Bitcoin() {}
Bitcoin::Bitcoin(const Bitcoin& other) : _data(other._data) {}
Bitcoin& Bitcoin::operator=(const Bitcoin& other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

const char* Bitcoin::DataNotFoundException::what() const throw() {
    return "Error: Data not found for the given date.";
}

static void getDate(const std::string& dateStr)
{

    if (dateStr[4] != '-' || dateStr[7] != '-')
        throw std::runtime_error(ERR_DATE + dateStr);
    std::string yearStr  = dateStr.substr(0, 4);
    std::string monthStr = dateStr.substr(5, 2);
    std::string dayStr   = dateStr.substr(8, 2);

    for (size_t i = 0; i < 4; ++i) if (!isdigit(yearStr[i])) throw std::runtime_error(ERR_YEAR + yearStr);
    for (size_t i = 0; i < 2; ++i) { 
        if (!isdigit(monthStr[i])) throw std::runtime_error(ERR_MONTH_INV + monthStr); 
        if (!isdigit(dayStr[i]))   throw std::runtime_error(ERR_DAY + dayStr); 
    }

    int year  = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day   = atoi(dayStr.c_str());


    if (month < 1 || month > 12) throw std::runtime_error(ERR_MONTH+ monthStr);
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysInMonth[1] = 29; // for the 29 of february
    }
    if (day < 1 || day > daysInMonth[month - 1])
        throw std::runtime_error(ERR_DAY_MONTH + dayStr);
}


void Bitcoin::loadData(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error(ERR_FILE);
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::string::size_type comma = line.find(',');
        if (comma == std::string::npos) return;       
        std::string date = line.substr(0, comma);
        if (!date.empty() && date[date.size() - 1] == '\r')
            date = date.substr(0, date.size() - 1);
    
        getDate(date);  // juste valide, ne retourne rien
        std::string dt = date;  // on garde la date pour affichage
    
        std::string bit  = line.substr(comma + 1);
        if (!bit.empty() && bit[bit.size() - 1] == '\r')
            bit = bit.substr(0, bit.size() - 1);
    
        std::cout << dt << " | " << bit << std::endl;
    }
}


float   Bitcoin::getValue(const std::string& date) const {
    (void)date;
    return 0.0f;
}

Bitcoin::~Bitcoin() {}