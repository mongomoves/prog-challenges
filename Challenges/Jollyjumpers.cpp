/*
    ID: 10038
    Determine if sequence of numbers is jolly.
    A sequence of n > 0 integers is called a jolly jumper if the 
    absolute values of the differences between successive 
    elements take on all possible values 1 through n − 1.

    Each line of input contains an integer n < 3,000 followed by 
    n integers representing the sequence
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

//Make a vector with n - 1 booleans
void fill_bool_vec(std::vector<bool> &vec, int n) 
{
    vec.clear();
    for(int i = 0; i < n - 1; i++)
    {
        vec.push_back(true);
    }
}

//Line from input to int vector.
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
    std::vector<int> numbers;       //The numbers from input, first element is "n".
    std::vector<bool> bool_vec;     //Vec to check differences against
    std::string line;
    int diff;
    bool jolly;
    while(getline(std::cin, line))  //For each line of input
    {
        std::stringstream strstream(line);
        sstream_to_vec(strstream, numbers);
        if(numbers.empty()) continue;
        if(numbers.at(0) <= 0 || numbers.at(0) >= 3000) continue; //Check if N is within bounds
        fill_bool_vec(bool_vec, numbers.at(0));
        jolly = true;
        for(auto it = numbers.begin() + 1; it != numbers.end(); ++it) //Iterate number sequence (skipping "n")
        {
            if(std::next(it) != numbers.end())  //If not on last element
            {
                diff = abs(*it - *(it + 1));                //Difference between current number and the following
                if(diff < numbers.at(0) && diff > 0)        //Makes sure we are in range
                {
                    if(bool_vec.at(diff - 1)) bool_vec.at(diff - 1) = false; //Flip to false if diff is part of the jolly sequence
                }
            }
        }
        //If any "number" is still true, then the sequence is not jolly.
        //Because all values in the range must be used.
        for(auto it = bool_vec.begin(); it != bool_vec.end(); ++it)
        {
            if(*it) jolly = false;
        }
        if(jolly) std::cout << "Jolly\n";
        else std::cout << "Not jolly\n";
    }
    return 0;
}