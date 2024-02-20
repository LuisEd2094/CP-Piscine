
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
    _db.insert(std::make_pair(date, price));
}

void BitcoinExchange::checkPriceDataBase(const std::string date, const float price)
{
    std::cout << "checking" << std::endl;
}
