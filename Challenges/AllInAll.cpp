/*
    ID: 10340
*/

#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string line;
    std::string s_str;
    std::string t_str;
    std::stringstream ss;
    size_t j;
    while(getline(std::cin, line))
    {
        std::stringstream ss(line);
        ss >> s_str;
        ss >> t_str;
        j = 0;
        for(size_t i = 0; i < t_str.length(); i++)
        {
            if(s_str[j] == t_str[i]) ++j;
        }
        if(j == s_str.length()) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
    return 0;
}