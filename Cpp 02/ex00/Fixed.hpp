#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>

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
        int m_fixedPoint;
};

#endif