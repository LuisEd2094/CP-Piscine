#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <cstdint>
class Data
{

    public:
        Data();
        ~Data();
        Data(const Data & other);
        Data& operator=(const Data& rhs);

        std::string m_name;
        int         m_age;
        static int  m_data_total;
};

#endif