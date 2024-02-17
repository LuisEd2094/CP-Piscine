/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:54:09 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:54:11 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{

    public:
        Data();
        ~Data();
        Data(const Data & other);
        Data& operator=(const Data& rhs);

        std::string _name;
        int         _age;
        static int  _data_total;
};

#endif
