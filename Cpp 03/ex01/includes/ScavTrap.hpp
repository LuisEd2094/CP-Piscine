/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:57:16 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 09:57:18 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &toCocpy);

    ScavTrap &operator=(const ScavTrap &scavtrap);

    ~ScavTrap();

    void attack(std::string const &target);
    void guardGate(void);
private:
    ScavTrap(void);
};
#endif
