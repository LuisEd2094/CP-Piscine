/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:38:21 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 12:38:22 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>


template <typename T>
class Array
{
    private:
            T*              _array;
        unsigned int    _size;
    public:

        Array() : _array( new T[0] ), _size(0) 
        {
            std::cout << "calling normal const" << std::endl;
            _array[0] = 0;
        };

        Array(unsigned int n) : _array(new T[n]), _size(n)
        {
            std::cout << "calling n const" << std::endl;
            for (unsigned int i = 0; i < _size; ++i) {
                _array[i] = 0; // Default initialization
        };
        }

        ~Array() { delete [] _array;};

        Array(const Array & other) : _array(new T[other._size]), _size(other._size) 
        {
            std::cout << "calling other const " << std::endl;
            for (unsigned int i = 0; i < _size; ++i)
                _array[i] = other._array[i];
        };

        Array& operator=(const Array& rhs)
        {
            std::cout << "Calling operator = " << std::endl;
            if (this != &rhs)
            {
                delete [] _array;
                _array = new T[rhs._size];
                _size = rhs._size;
                for (unsigned int i = 0; i < _size; ++i)
                    _array[i] = rhs._array[i];
            }
            return *this;
        };

        T& operator[] (int i) const
        {
            if (i < 0 || i >= static_cast<int>(_size)) 
                throw OutOfBounds();
            return _array[i];
        };

        unsigned int size(void) const
        {
            return _size;
        };
        class OutOfBounds : public std::exception
        {
            public:
                virtual const char* what() const throw()
                { return "Index out of bounds";}
        };

};

#endif
