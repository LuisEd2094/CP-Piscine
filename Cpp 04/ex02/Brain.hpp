#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <cstdlib>

class Brain
{
    public:
        Brain(void);
        Brain(const Brain& copy);
        Brain& operator=(const Brain& rhs);
        ~Brain(void);

        const std::string& getIdea(int index) const;
    private:
        std::string m_ideas[100];
};

#endif