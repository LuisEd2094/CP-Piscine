#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <cstdio>
# include <cstdlib>
# include <iomanip> 
#include <cmath>


class BitcoinExchange
{
    private:
        std::map<std::string, double> _map;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & other);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
};

#endif