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
    const static unsigned int _base_hp = 100;
    const static unsigned int _base_energy = 50;
    const static unsigned int _base_dmg = 20;
};

#endif
