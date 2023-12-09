#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
class Cat : public Animal
{
    public:
        Cat(void);
        Cat(std::string type);
        Cat(const Cat& other);
        Cat& operator=(const Cat& rhs);
        ~Cat(void);

        void makeSound(void) const;
        Brain *getBrain(void) const;
    private:
        Brain *m_brain;
};

#endif