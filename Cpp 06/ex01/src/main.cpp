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
#include <cstdint>


int main()
{
    Data data;


    std::cout << data._age << " " << data._name << " " << Data::_data_total << std::endl;
    std::cout << "data address :" <<  &data << std::endl;

    uintptr_t ptr = Serializer::serialize(&data);

    std::cout << &ptr << std::endl;

    Data * data_d = Serializer::deserialize(ptr);

    std::cout << data_d->_age << " " << data_d->_name << " " << Data::_data_total << std::endl;
    std::cout << "data_d dereference address :" << &*data_d << std::endl;

    std::cout << " are they equal? = " << (&*data_d == &data) << std::endl;
}
