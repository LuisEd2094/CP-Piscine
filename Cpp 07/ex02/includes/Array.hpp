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
        T*  m_array;
        unsigned int m_size;
    public:
        Array() : m_array( new T[0] ), m_size(0) {};

        Array(unsigned int n) : m_array(new T[n]), m_size(n)
        {
            for (unsigned int i = 0; i < m_size; ++i) {
                m_array[i] = T(); // Default initialization
        };
        }

        ~Array() { delete [] m_array;};

        Array(const Array & other) : m_array(new T(other.m_size)), m_size(other.m_size) {
            for (unsigned int i = 0; i < m_size; ++i)
                m_array[i] = other.m_array[i];
        };

        Array& operator=(const Array& rhs){
            if (this != &rhs)
            {
                delete [] m_array;
                m_array = new T[rhs.m_size];
                m_size = rhs.m_size;
                for (unsigned int i = 0; i < m_size; ++i)
                    m_array[i] = rhs.m_array[i];
            }
            return *this;
        };

        T& operator[] (unsigned int i) const{
            if (i >= m_size)
                throw OutOfBounds();
            return m_array[i];
        };

        unsigned int size(void) const{
            return m_size;
        };
        class OutOfBounds : public std::exception
        {
            public:
                virtual const char* what() const throw()
                { return "Index out of bounds";}
        };

};

#endif
