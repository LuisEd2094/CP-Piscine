#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>
# include <random>
# include <ctime>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
