/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:29:13 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 13:29:14 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <cmath>
#include <iostream>

class Fixed
{
public:
    Fixed(void);
    Fixed(const int);
    Fixed(const float);
    Fixed(const Fixed &);

    ~Fixed();

    Fixed &operator=(const Fixed &);

    bool operator<(const Fixed &);
    bool operator>(const Fixed &);
    bool operator>=(const Fixed &);
    bool operator<=(const Fixed &);
    bool operator==(const Fixed &);
    bool operator!=(const Fixed &);

    Fixed operator+(const Fixed &);
    Fixed operator-(const Fixed &);
    Fixed operator*(const Fixed &);
    Fixed operator/(const Fixed &);

    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(const int);

    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &, Fixed &);
    static const Fixed &min(const Fixed &, const Fixed &);
    static Fixed &max(Fixed &, Fixed &);
    static const Fixed &max(const Fixed &, const Fixed &);

private:
    static int const fraction = 8;
    int _fixedPoint;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
