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

class DiamondTrap : public virtual ClapTrap, public FragTrap, public ScavTrap
{
public:
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &toCocpy);

    DiamondTrap &operator=(const DiamondTrap &DiamondTrap);

    ~DiamondTrap(void);

    using ScavTrap::attack;
    void whoAmI(void);

private:
    DiamondTrap(void);
    std::string _name;
};
#endif
