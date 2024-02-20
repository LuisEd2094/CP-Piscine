/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:39:48 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/02 09:39:54 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <BitcoinExchange.hpp>
#include <sstream>


#define FILE_PATH "/Users/lsoto-do/core05/CP-Piscine/Cpp 09/ex00/dataBase/data.csv"

void exitError(std::string error)
{
    std::cerr <<"Error: " << error << std::endl;
    std::exit(EXIT_FAILURE);
}

bool isValidDateFormat(const std::string &dateString) 
{
    int year;
    int month;
    int day;

    if (dateString.size() != 10)
        return (false);
    if (dateString[4] != '-' || dateString[7] != '-')
        return (false);
    year = atoi(dateString.substr(0, 4).c_str());
    month = atoi(dateString.substr(5, 2).c_str());
    day = atoi(dateString.substr(8, 2).c_str());
    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
        return (false);
    return (true);
}

bool    validINPUTPrice(float price)
{

    return (!(price < 0 || price > 1000));
}

bool    validCSVPrice(float price)
{
    return (price >= 0);
}

bool    validFirstLine(std::string line, std::string firstLine)
{
    return (line != firstLine);
}

void    handleInFileError(std::string err)
{
    std::cerr << err << std::endl;
}

void    handleCSVError(std::string err)
{
    exitError(err);
}

void    workOnFile(BitcoinExchange &data, std::string filePath, std::string sep, std::string firstLine, void (BitcoinExchange::*f)(std::string, float), bool (*validPrice)(float), void (*handleError)(std::string))
{
    std::ifstream   file;
    std::string     line;
    std::size_t     found;
    std::string     date;
    std::string     priceStr;
    bool            err;
    char            *buffer;
    float           price;

    file.open(filePath, std::ifstream::in);
    if (file.good())
    {
        //Skip header line
        std::getline(file, line);
        if (validFirstLine(line, firstLine))
            exitError("Check the first line on file: " + filePath +" should be " + firstLine +" not:" + line);
        while (std::getline(file, line))
        {
            found = line.find(sep,  0);
            date = line.substr(0, found);
            if (!isValidDateFormat(date))
            {
                ((*handleError)("Invalid date on " + filePath + ": " + date));
                continue;
            }
            priceStr = line.substr(found + sep.length());
            price = std::strtod(priceStr.c_str(), &buffer);
            if (errno == ERANGE || buffer == priceStr)
            {
                (*handleError)("Couldn't convert " + priceStr + " to float on line " + \
                line + " on file: " + filePath);
                continue;
            }
            if (!(*validPrice)(price))
            {
                ((*handleError)("Invalid price: " + line + " on file: " + filePath));
                continue;
            }
            (data.*f)(date, price);
        }
    }
    else
        exitError("There was an issue opening the file " + filePath);
    file.close();

}

int main( int argc, char *argv[] )
{
    BitcoinExchange data;

    if (argc != 2)
    {
        std::cerr << "Incorrect use. Provide me with a file that contains data in a date | value format" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    workOnFile(data, FILE_PATH, "," , "date,exchange_rate",  &BitcoinExchange::addToDataBase, &validCSVPrice, &handleCSVError);
    workOnFile(data, static_cast<std::string>(argv[1]), " | " , "date | value", &BitcoinExchange::checkPriceDataBase, &validINPUTPrice, &handleInFileError);
    std::cout << std::endl;
}
