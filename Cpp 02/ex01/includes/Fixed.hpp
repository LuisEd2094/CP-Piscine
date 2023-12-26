/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:22:07 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 13:22:08 by lsoto-do         ###   ########.fr       */
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

        Fixed& operator=(const Fixed& toCopy);

        int     getRawBits(void) const;

        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;
    
    private:
        static int const fraction = 8;
        int m_fixedPoint;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
