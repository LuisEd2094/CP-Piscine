#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template <typename T>
void easyfind (T& container, int value)
{
    if (std::find (container.begin(), container.end(), value) != container.end())
        std::cout << "Found." << std::endl;
    else 
        throw std::runtime_error("Value not found in container");
}

#endif
