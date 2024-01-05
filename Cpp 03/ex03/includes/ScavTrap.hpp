/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:05:38 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:05:40 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &toCocpy);

    ScavTrap &operator=(const ScavTrap &scavtrap);

    ~ScavTrap(void);

    void attack(std::string const &target);
    void guardGate(void);

protected:
    ScavTrap(void);
    unsigned int _hp;
    unsigned int _energy;
    unsigned int _dmg;
};
#endif
