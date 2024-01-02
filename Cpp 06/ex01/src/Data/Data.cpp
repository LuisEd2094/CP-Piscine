/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:54:22 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:54:25 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp" 

int Data::_data_total = 0;

Data::Data(void) : 
    _name("Default"),
    _age(0)
{
    _data_total += 1;
}
Data::Data(const Data& src) :
    _name(src._name),
    _age(src._age)
    {
        _data_total += 1;
    }
Data& Data::operator=(const Data& rhs) {
    if (this != &rhs)
    {
        _name = rhs._name;
        _age = rhs._age;
    }
    return (*this);
}

Data::~Data() {
    _data_total -= 1;
}
