
#include "BitcoinExchange.hpp" 

BitcoinExchange::BitcoinExchange(void) 
{
    // Lets check a better way to open the file
    std::setprecision(2);
    FILE *file = fopen("/home/luised94/CP-Piscine/Cpp 09/ex00/src/BitcoinExchange/data.csv", "r");

    char date[20];
    double value;

    if (file == NULL)
    {
        std::cerr << "Error opening file data.csv" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    else
    {

        while (fscanf(file, "%[^,],%lf\n", date, &value) != EOF)
        {
            value = round(value * 100.0) / 100.0;
            _map.insert(std::make_pair(date, value));
            //std::cout << "Date: " << date << ", value: " << value << std::endl;

        }
    }

}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) 
{
    (void)rhs;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}