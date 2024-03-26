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
        void workOnFile(std::string filePath, std::string sep, std::string firstLine, void (BitcoinExchange::*f)(std::string, float), bool (BitcoinExchange::*validPrice)(float, const std::string&), void (BitcoinExchange::*handleError)(std::string));

        void addToDataBase(const std::string date, const float price);
        void checkPriceDataBase(const std::string date, const float price);
        bool validFirstLine(std::string line, std::string firstLine);
        void exitError(std::string error);
        bool isValidDateFormat(const std::string &dateString);
        bool validCSVPrice(float price, const std::string& priceStr);
        bool validINPUTPrice(float price, const std::string& strPrice);
        void handleCSVError(std::string err);
        void handleInFileError(std::string err);
        std::string getSep(std::string firstLine, std::string first, std::string second);
    public:
        BitcoinExchange();
        BitcoinExchange(std::string filePath);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & other);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        
        void checkFileWithDB(std::string filePath, std::string firstLine);
};

#endif
