
#include "BitcoinExchange.hpp" 
#define DEFAULT_DB "./dataBase/data.csv"

BitcoinExchange::BitcoinExchange(void) 
{
    std::string firstLine = "date,exchange_rate";
    std::string sep = getSep(firstLine, "date", "exchange_rate");

    workOnFile(DEFAULT_DB, sep, firstLine, &BitcoinExchange::addToDataBase, &BitcoinExchange::validCSVPrice, &BitcoinExchange::handleCSVError);
}
BitcoinExchange::BitcoinExchange(std::string filePath)
{
    std::string firstLine = "date,exchange_rate";
    std::string sep = getSep(firstLine, "date", "exchange_rate");

    workOnFile(filePath, sep, firstLine, &BitcoinExchange::addToDataBase, &BitcoinExchange::validCSVPrice, &BitcoinExchange::handleCSVError);
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) 
{
    *this = src;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) 
{
    if (this != &rhs)
    {
        _db = rhs._db;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}


std::string BitcoinExchange::getSep(std::string firstLine, std::string first, std::string second)
{
    std::size_t datePos = firstLine.find(first);
    if (datePos != std::string::npos)
    {
        std::size_t exchangeRatePos = firstLine.find(second, datePos);
        if (exchangeRatePos != std::string::npos)
        {
            std::size_t length = exchangeRatePos - (datePos + first.length());
            return (firstLine.substr(datePos + first.length(), length));
        }
    }
    exitError("Couldn't get separator from the first line: " + firstLine);
    return (NULL);

}

void    BitcoinExchange::handleInFileError(std::string err)
{
    std::cerr << err << std::endl;
}

void    BitcoinExchange::handleCSVError(std::string err)
{
    exitError(err);
}


bool    BitcoinExchange::validINPUTPrice(float price, const std::string& priceStr)
{
    return ((price >= 0 && price <= 1000) && priceStr.find_first_not_of(".0123456789") == std::string::npos);
}

bool    BitcoinExchange::validCSVPrice(float price, const std::string& priceStr)
{
    return (price >= 0 && priceStr.find_first_not_of(".0123456789") == std::string::npos  );
}

bool    BitcoinExchange::validFirstLine(std::string line, std::string firstLine)
{
    return (line != firstLine);
}

void BitcoinExchange::exitError(std::string error)
{
    std::cerr <<"Error: " << error << std::endl;
    std::exit(EXIT_FAILURE);
}

bool BitcoinExchange::isValidDateFormat(const std::string &dateString) 
{
    int year;
    int month;
    int day;

    if (dateString.size() != 10)
        return (false);
    if (dateString.find_first_not_of("0123456789-") != std::string::npos)
        return (false);
    if (dateString[4] != '-' || dateString[7] != '-')
        return (false);
    if (dateString.substr(0, 4).find_first_not_of("0123456789") != std::string::npos || \
        dateString.substr(5, 2).find_first_not_of("0123456789") != std::string::npos || \
        dateString.substr(8, 2).find_first_not_of("0123456789") != std::string::npos)
        return (false);
    year = atoi(dateString.substr(0, 4).c_str());
    month = atoi(dateString.substr(5, 2).c_str());
    day = atoi(dateString.substr(8, 2).c_str());
    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
        return (false);
    return (true);
}

void    BitcoinExchange::workOnFile(std::string filePath, std::string sep, std::string firstLine, void (BitcoinExchange::*f)(std::string, float), bool (BitcoinExchange::*validPrice)(float, const std::string&), void (BitcoinExchange::*handleError)(std::string))
{
    std::ifstream   file;
    std::string     line;
    std::size_t     found;
    std::string     date;
    std::string     priceStr;
    char            *buffer;
    float           price;

    file.open(filePath.c_str(), std::ifstream::in);
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
                ((this->*handleError)("Invalid date on " + filePath + ": " + date));
                continue;
            }
            priceStr = line.substr(found + sep.length());
            price = std::strtod(priceStr.c_str(), &buffer);
            if (errno == ERANGE || buffer == priceStr)
            {
                (this->*handleError)("Couldn't convert " + priceStr + " to float on line " + \
                line + " on file: " + filePath);
                continue;
            }
            if (!(this->*validPrice)(price, priceStr) )
            {
                ((this->*handleError)("Invalid price: " + line + " on file: " + filePath));
                continue;
            }
            (this->*f)(date, price);
        }
    }
    else
        exitError("There was an issue opening the file " + filePath);
    file.close();

}


void BitcoinExchange::addToDataBase(const std::string date, const float price)
{
    _db.insert(std::make_pair(date, price));
}

void BitcoinExchange::checkPriceDataBase(const std::string date, const float price)
{
    std::map<std::string, float>::iterator it = _db.lower_bound(date);
    if (it->first != date && it != _db.begin())
        --it;
    std::cout << date << " => " << price << " = " <<  it->second * price << std::endl; 
}



void BitcoinExchange::checkFileWithDB(std::string filePath, std::string firstLine)
{
    std::string sep = getSep(firstLine, "date", "value");
    workOnFile(filePath, sep, firstLine, &BitcoinExchange::checkPriceDataBase, &BitcoinExchange::validINPUTPrice, &BitcoinExchange::handleInFileError);
}
