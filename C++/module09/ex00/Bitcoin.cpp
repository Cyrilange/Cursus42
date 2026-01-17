/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitcoin.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:26 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/17 16:21:50 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitcoin.hpp"

Bitcoin::Bitcoin() {}
Bitcoin::Bitcoin(const Bitcoin &other) : _data(other._data) {}
Bitcoin &Bitcoin::operator=(const Bitcoin &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

const char *Bitcoin::DataNotFoundException::what() const throw()
{
    return "Error: bad input => no data found.";
}

static void trimCarriageReturn(std::string &str)
{
    if (!str.empty() && str[str.size() - 1] == '\r')
        str.erase(str.size() - 1);
}

static float ft_stof(const std::string &str)
{
    std::istringstream iss(str);
    float result;
    char extra;

    if (!(iss >> result))
        throw std::runtime_error(ERR_INPUT + str);
    if (iss >> extra)
        throw std::runtime_error(ERR_INPUT + str);
    return result;
}

static void getDate(const std::string &dateStr)
{
    if (dateStr.length() < 10)
        throw std::runtime_error(ERR_DATE + dateStr);
    if (dateStr[4] != '-' || dateStr[7] != '-')
        throw std::runtime_error(ERR_DATE + dateStr);

    std::string yearStr = dateStr.substr(0, 4);
    std::string monthStr = dateStr.substr(5, 2);
    std::string dayStr = dateStr.substr(8, 2);

    for (size_t i = 0; i < 4; ++i)
        if (!std::isdigit(yearStr[i]))
            throw std::runtime_error(ERR_YEAR + yearStr);
    for (size_t i = 0; i < 2; ++i)
    {
        if (!std::isdigit(monthStr[i]))
            throw std::runtime_error(ERR_MONTH_INV + monthStr);
        if (!std::isdigit(dayStr[i]))
            throw std::runtime_error(ERR_DAY + dayStr);
    }

    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (month < 1 || month > 12)
        throw std::runtime_error(ERR_MONTH + monthStr);

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        throw std::runtime_error(ERR_DAY_MONTH + dayStr);
}

void Bitcoin::parseLine(const std::string &line)
{
    std::string date;
    std::string value;

    std::string::size_type sep = line.find(" | ");
    if (sep != std::string::npos)
    {
        date = line.substr(0, sep);
        value = line.substr(sep + 3);
    }
    else
    {
        std::string::size_type comma = line.find(',');
        if (comma != std::string::npos)
        {
            date = line.substr(0, comma);
            value = line.substr(comma + 1);
        }
        else
            throw std::runtime_error(ERR_INPUT + line);
    }
    trimCarriageReturn(date);
    trimCarriageReturn(value);
    float fvalue = ft_stof(value);
    if (fvalue < 0)
        throw std::runtime_error(ERR_POSITIVE);
    if (fvalue > MAX_VALUE)
        throw std::runtime_error(ERR_INT);

    getDate(date);
    float rate = Bitcoin::getValue(date);
    std::cout << date << " => " << value << " = " << fvalue * rate << std::endl;
}

void Bitcoin::loadData(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error(ERR_FILE);

    std::string line;
    if (!std::getline(file, line))
        return;

    if (line != "date,exchange_rate" && line != "date | value")
    {
        try
        {
            parseLine(line);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        try
        {
            parseLine(line);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Bitcoin::loadDB(const std::string &dbFilename)
{
    std::ifstream dbFile(dbFilename.c_str());
    if (!dbFile.is_open())
        throw std::runtime_error(ERR_FILE);

    std::string line;
    std::getline(dbFile, line);
    while (std::getline(dbFile, line))
    {
        if (line.empty())
            continue;

        std::string::size_type comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        std::string date = line.substr(0, comma);
        std::string valueStr = line.substr(comma + 1);

        try
        {
            float value = ft_stof(valueStr);
            _data[date] = value;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

float Bitcoin::getValue(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);

    if (it != _data.end() && it->first == date)
        return it->second;
    else
    {
        if (it == _data.begin())
            throw DataNotFoundException();
        --it;
        return it->second;
    }
}

Bitcoin::~Bitcoin() {}