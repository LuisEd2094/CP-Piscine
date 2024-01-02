/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:05:11 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:05:12 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>


class ClapTrap
{
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& toCopy);
        ClapTrap& operator=(const ClapTrap& toCopy);

        ~ClapTrap();

        bool    canTakeAction();
        void    attack(std::string const& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
    
    protected:
        ClapTrap(void);
        std::string     _name;
        unsigned int    _hp;
        unsigned int    _energy;
        unsigned int    _dmg;
};

#endif
