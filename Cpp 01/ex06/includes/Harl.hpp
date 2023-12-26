/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:00:22 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 11:00:24 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
    
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif

