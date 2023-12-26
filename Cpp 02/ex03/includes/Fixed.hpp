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
# define FIXED_HPP

# include <string>
# include <cmath>
# include <iostream>


class Fixed
{
    public:
        Fixed();
        Fixed(int const val);
        Fixed(float const val);
        Fixed(const Fixed& toCopy);

        ~Fixed();

        Fixed&  operator=(const Fixed& toCopy);

        bool    operator<(const Fixed& fixed);
        bool    operator>(const Fixed& fixed);		
        bool    operator>=(const Fixed& fixed);		
        bool    operator<=(const Fixed& fixed);		
        bool    operator==(const Fixed& fixed);		
        bool    operator!=(const Fixed& fixed);

        Fixed   operator+(const Fixed& fixed);		
        Fixed   operator-(const Fixed& fixed);		
        Fixed   operator*(const Fixed& fixed);		
        Fixed   operator/(const Fixed& fixed);		

        Fixed&  operator++();					 
        Fixed&  operator--();					 
        Fixed   operator++(int);					 
        Fixed   operator--(int);					 

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;

        static          Fixed&  min(Fixed& a, Fixed& b);
        static const    Fixed&  min(const Fixed&a, const Fixed& b);
        static          Fixed&  max(Fixed& a, Fixed& b);
        static const    Fixed&  max(const Fixed& a, const Fixed& b);
    
    private:
        static int const fraction = 8;
        int m_fixedPoint;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
