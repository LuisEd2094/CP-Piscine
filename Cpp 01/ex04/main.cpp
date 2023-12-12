#include <string>
#include <cstring>
#include <cerrno>
#include <iostream>
#include <fstream>

void replace(const std::string& string_to_replace, const std::string& string_to_search, std::ifstream& in_file, std::string file_name)
{
    std::ofstream out_file(file_name.append(".replace").c_str());
    std::string line;
    std::size_t found;

    while (in_file.good() && out_file.good())
    {
        std::getline(in_file, line);
        
        found = line.find(string_to_search, 0);
        while (found != std::string::npos)
        {
            line.erase(found, string_to_search.length());
            line.insert(found, string_to_replace);
            found = line.find(string_to_search, found);
        }
        out_file << line;
        if (in_file.eof())
            break;
        out_file << std::endl; 
    }
    out_file.close();
}

void sed(char **argv)
{
    std::string file_name(argv[1]);
    std::string string_to_search(argv[2]);
    std::string string_to_replace(argv[3]);
    std::ifstream in_file(file_name.c_str());
    

    if (in_file.is_open() && in_file.good())
    {
        if (in_file.peek() == std::ifstream::traits_type::eof())
            std::cout << "Error: Empty file" << std::endl;
        else
        {
            replace(string_to_replace, string_to_search, in_file, file_name);
            in_file.close();
        }
    }
    else
        std::cout << "Error: " << std::strerror(errno) << std::endl;
    return;
}

int main (int argc, char ** argv)
{
    if (argc == 4)
        sed(argv);
    else
        std::cout << "Wrong usage. run ./sed <filename> <string to search and reaplace> <string to be replaced>" << std::endl;
    return (0);    
}