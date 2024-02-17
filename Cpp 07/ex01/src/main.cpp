/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:34:13 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 11:34:14 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void add_one(int &a) {a++;}


int main()
{
    int int_array[] = {1, 2, 3, 4, 5};
    std::string str[] = {
        "Hola",
        "Cara", 
        "de perola"
    };
    size_t int_length = sizeof(int_array) / sizeof(int_array[0]);
    size_t str_length = sizeof(str) / sizeof(str[0]);


    std::cout << "OG int array" << std::endl;
    for (size_t i = 0; i < int_length; ++i)
        std::cout << int_array[i] << std::endl;
    std::cout << "OG string array" << std::endl;
    for (size_t i = 0; i < str_length; ++i)
        std::cout << str[i] << std::endl;
    std::cout << std::endl;

    std::cout << "Calling iter template with add_one function" << std::endl;
    iter(int_array, int_length, add_one);
    std::cout << "Calling print_element tempalte with iter to print after adding one" << std::endl;
    iter(int_array, int_length, print_element<int>);

    std::cout << "Calling for loop" <<  std::endl;
    for (size_t i = 0; i < int_length; ++i)
        std::cout << int_array[i] << std::endl;
    std::cout << std::endl;

    std::cout << "Calling print element template for str array" << std::endl;
    iter(str, str_length, print_element<std::string>);
}
