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

int main( void )
{
    BitcoinExchange data;


    std::map<std::string, int> map;

    map.insert(std::make_pair("10", 10));
    map.insert(std::make_pair("15", 50));
    map.insert(std::make_pair("11", 70));


    std::string requestedDate = "12";

    std::map<std::string, int>::iterator it = map.lower_bound(requestedDate);
    if (it->first != requestedDate && it != map.begin())
        --it;
    std::cout << it->first << " " << it->second << std::endl; 
/* 
try
{
    std::cout << map.at(requestedDate) << std::endl;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';

    std::map<int, int>::iterator it = map.lower_bound(requestedDate);

    std::map<int, int>::iterator end = map.end();

    std::cout << end->first << "\n";

    if (it != map.begin())
        --it;
if ((it == map.end()) && it->first != requestedDate)
     {
        // Adjust iterator to the closest lower date
        {
            --it;
        }
    }

    std::cout << it->first <<" "<< it->second << std::endl;
}
 */

}
