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