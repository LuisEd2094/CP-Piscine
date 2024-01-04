/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:05:35 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:05:36 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap &toCocpy);

    FragTrap &operator=(const FragTrap &FragTrap);

    ~FragTrap(void);

    void attack(std::string const &target);
    void highFivesGuys(void);

private:
    FragTrap(void);
};
#endif
