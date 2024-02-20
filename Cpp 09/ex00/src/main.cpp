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


void    loadDBToData(BitcoinExchange &data)
{
    std::string     dataBaseFilePath = FILE_PATH;
    std::ifstream   file;
    std::string     line;
    std::size_t     found;
    std::string     date;
    std::string     priceStr;
    char            *buffer;
    float           price;

    file.open(dataBaseFilePath, std::ifstream::in);
    if (file.good())
    {
        //Skip header line
        std::getline(file, line);
        while (std::getline(file, line))
        {
            found = line.find(",", 0);
            date = line.substr(0, found);
            if (!isValidDateFormat(date))
                exitError("Invalid date on the csv file: " + date);
            priceStr = line.substr(found + 1);
            price = std::strtod(priceStr.c_str(), &buffer);
            if (errno == ERANGE || buffer == priceStr)
                exitError("Couldn't convert " + priceStr + " to float on line " + \
                line);
            if (price < 0)
                exitError("Prices on csv file can't be negative: " + line);
            data.addToDataBase(date, price);
        }
    }
    else
        exitError("There was an issue opening the file " + dataBaseFilePath);
    file.close();

}

void loadFileToData(BitcoinExchange &data, std::string argv)
{
    
}

int main( int argc, char *argv[] )
{
    BitcoinExchange data;

    if (argc != 2)
    {
        std::cerr << "Incorrect use. Provide me with a file that contains data in a date | value format" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    loadDBToData(data);
    loadFileToData(data, static_cast<std::string>(argv[1]));





}
