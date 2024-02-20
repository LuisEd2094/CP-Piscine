
#include "BitcoinExchange.hpp" 

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) 
{
    (void)rhs;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::addToDataBase(const std::string date, const float price)
{
    _map.insert(std::make_pair(date, price));
}

