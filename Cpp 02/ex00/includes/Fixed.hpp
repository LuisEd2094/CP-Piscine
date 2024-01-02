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
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& toCopy);

        Fixed& operator=(const Fixed& toCopy);

        ~Fixed();

        int     getRawBits(void) const;

        void    setRawBits(int const raw);
    
    private:
        static int const fraction = 8;
        int _fixedPoint;
};

#endif

