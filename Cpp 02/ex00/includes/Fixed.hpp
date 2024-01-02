/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:19:38 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 13:19:42 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
public:
    Fixed(void);
    Fixed(const Fixed &);

    Fixed &operator=(const Fixed &);

    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(const int);

private:
    static const int fraction = 8;
    int _fixedPoint;
};

#endif
