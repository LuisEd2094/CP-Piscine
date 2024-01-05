/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:05:30 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:05:31 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : virtual public ClapTrap, virtual public FragTrap, virtual public ScavTrap
{
public:
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &toCocpy);

    DiamondTrap &operator=(const DiamondTrap &DiamondTrap);

    ~DiamondTrap(void);

    using ScavTrap::attack;
    using FragTrap::_hp;
    using ScavTrap::_energy;
    using FragTrap::_dmg;

    void whoAmI(void);
protected:
    DiamondTrap(void);
private:
    std::string _name;
};

std::ostream& operator<< (std::ostream& stream, const DiamondTrap& DiamondTrap);
#endif
