/*
    ID: 10038
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void fill_bool_vec(std::vector<bool> &vec, int n) 
{
    vec.clear();
    for(int i = 0; i < n - 1; i++)
    {
        vec.push_back(true);
    }
}

void sstream_to_vec(std::stringstream &ss, std::vector<int> &vec)
{
    int nbr;
    vec.clear();
    while(ss >> nbr) 
    {
        vec.push_back(nbr);
    }    
}

int main()
{
    std::vector<int> numbers;
    std::vector<bool> bool_vec;
    std::string line;
    int diff;
    bool jolly;
    while(std::getline(std::cin, line))
    {
        std::stringstream strstream(line);
        sstream_to_vec(strstream, numbers);
        jolly = true;
        if(numbers.empty()) continue;
        if(numbers[0] <= 0 || numbers[0] >= 3000) continue; //N is within bounds
        fill_bool_vec(bool_vec, numbers[0]);
        for(auto it = numbers.begin() + 1; it != numbers.end(); ++it)
        {
            if(std::next(it) != numbers.end()) 
            {
                diff = abs(*it - *(it + 1));
                if(diff >= numbers[0]) jolly = false;
                if(bool_vec[diff - 1]) bool_vec[diff - 1] = false;
            }
        }
        if(jolly)
        {
            for(auto it = bool_vec.begin(); it != bool_vec.end(); ++it)
            {
                if(*it) jolly = false;
            }
        }
        if(jolly) std::cout << "Jolly\n";
        else std::cout << "Not jolly\n";
    }
}