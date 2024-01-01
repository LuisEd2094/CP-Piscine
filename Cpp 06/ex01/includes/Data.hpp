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
# include <cstdint>
class Data
{

    public:
        Data();
        ~Data();
        Data(const Data & other);
        Data& operator=(const Data& rhs);

        std::string m_name;
        int         m_age;
        static int  m_data_total;
};

#endif
