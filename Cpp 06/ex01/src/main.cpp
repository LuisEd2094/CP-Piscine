/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:54:32 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:54:34 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"


int main()
{
    Data data;


    std::cout << "Data. Age: " << data._age << " Name: " << data._name << " Total: " << Data::_data_total << std::endl;
    std::cout << "data address :" <<  &data << std::endl;

    uintptr_t ptr = Serializer::serialize(&data);

    std::cout << &ptr << std::endl;

    Data * data_d = Serializer::deserialize(ptr);

    std::cout << "Data_d. Age: " << data_d->_age << " Name: " << data_d->_name << " Total: " << Data::_data_total << std::endl;
    std::cout << "data_d dereference address :" << &*data_d << std::endl;

    std::cout << "Are they equal? = " << (&(*data_d) == &data) << std::endl;
}
