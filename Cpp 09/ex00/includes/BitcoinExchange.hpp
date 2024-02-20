#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <cstdlib>
# include <iomanip> 
# include <cmath>
# include <errno.h>


class BitcoinExchange
{
    private:
        std::map<std::string, float> _db;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & other);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        
        void addToDataBase(const std::string date, const float price);
        void checkPriceDataBase(const std::string date, const float price);
};

#endif
