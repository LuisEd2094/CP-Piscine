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
        this->m_ideas[i] = examples[rand() % (sizeof(examples) / sizeof(examples[0]))];
    std::cout << "Brain(void) called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->m_ideas[i] = rhs.m_ideas[i];
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
        return (this->m_ideas[index]);
    else
    {
        std::cout << "Invalid index, provide a 0-99 index" << std::endl;
        static const std::string emptyString;
        return emptyString;
    }
}