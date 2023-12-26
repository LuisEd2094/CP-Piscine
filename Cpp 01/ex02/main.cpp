/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:56:03 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 10:56:04 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


void    print_address(std::string &str, std::string *&stringPTR, std::string &stringREF)
{
    std::cout << "Str Address :" << &str << std::endl;
    std::cout << "stringREF Address :" << &stringREF << std::endl;
    std::cout << "stringPTR Address :" << &stringPTR << std::endl;
}

void    print_content(std::string &str, std::string *&stringPTR, std::string &stringREF)
{
    std::cout << "Str content :" << str << std::endl;
    std::cout << "stringREF content :" << stringREF << std::endl;
    std::cout << "stringPTR content :" << *stringPTR << std::endl;   
}
    

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    print_address(str, stringPTR, stringREF); 
    std::cout << std::endl;
    print_content(str, stringPTR, stringREF);
    return (0);
}
