/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:26:00 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:26:01 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain(void)
{
    const std::string examples[] = {
        "I want to eat",
        "I want to sleep",
        "I want to run", 
        "I want to poop",
        "I want to pee",
        "I am",
    };
    for (int i = 0; i < 100; i++)
        _ideas[i] = examples[rand() % (sizeof(examples) / sizeof(examples[0]))];
    std::cout << "Brain(void) called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = rhs._ideas[i];
	}
    std::cout << "Brain = operator called" << std::endl;
	return (*this);
}


Brain::Brain(const Brain& copy)
{
    *this = copy;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain deconstructor called" << std::endl;
}

const std::string& Brain::getIdea(int index) const
{
    if (index < 100 && index >= 0)
        return (_ideas[index]);
    else
    {
        std::cout << "Invalid index, provide a 0-99 index" << std::endl;
        static const std::string emptyString;
        return emptyString;
    }
}
