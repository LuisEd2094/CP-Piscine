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

#include <BitcoinExchange.hpp>


/*BitcoinExcange can be init with or without a dataBase. If using default, it'd use the default dataBase provided by subject.
Otherwise it'd save the info from the file pass on construction.

If there are any issues with the format on the csv file it'd close the program.
CSV files should have on their first line 
date,exchange_rate


After everything loads correctly, you can then call checkFileWithDB
It requires a std::string for an input fileand the first line on the file
It'd check the first line to get the format of the file

it needs to have date and value, and some form of separator inbetween, it'd then check each value on the file to make sure it complies with this
It'd check the file, in case there is an error it'd print an appropiate error message to STDERR (invalid date, negative number, number > 1000),
otherwise it'd multiply the value to the closest lower date on date base. 

For example. If you request 2012-01-11 | 1 
I'd give you the price for that date or the closet one before it*/

int main( int argc, char *argv[] )
{
    BitcoinExchange *data = new BitcoinExchange();

    if (argc != 2)
    {
        std::cerr << "Incorrect use. Provide me with a file that contains data in a date | value format" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    BitcoinExchange test;
    test = *data;
    delete data;
    test.checkFileWithDB(static_cast<std::string>(argv[1]), "date | value");
}
