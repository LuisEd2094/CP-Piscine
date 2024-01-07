/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:26:04 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:26:05 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <cstdlib>

class Brain
{
public:
    Brain(void);
    Brain(const Brain &copy);
    Brain &operator=(const Brain &rhs);
    ~Brain(void);

    const std::string &getIdea(int index) const;

private:
    std::string _ideas[100];
};

#endif
