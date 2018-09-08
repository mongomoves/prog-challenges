/*
    ID: 839
*/

//WL DL WR DR
//Wl * Dl = Wr * Dr

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int same;

std::vector<int> strToVec(std::string line)
{
    int nbr;
    std::vector<int> vec;
    std::stringstream ss(line);
    while(ss >> nbr) vec.push_back(nbr);
    return vec;
}

int foo(std::vector<int> vec)
{
    int Wl = vec[0], Dl = vec[1], Wr = vec[2], Dr = vec[3];
    if(Wl == 0) 
    {
        std::string line;
        std::vector<int> vec2;
        getline(std::cin,line);
        vec2 = strToVec(line);
        Wl = foo(vec2);
    }
    if(Wr == 0)
    {
        std::string line;
        std::vector<int> vec2;
        getline(std::cin,line);
        vec2 = strToVec(line);
        Wr = foo(vec2);
    }
    if(Wl * Dl != Wr * Dr) ++same;
    return Wl + Wr;
}

int main()
{    
    int cases;
    std::string line;
    std::cin >> cases;
    std::vector<int> inputVec;
    getline(std::cin, line); //Get rid of first blank line
    while(cases)
    {
        same = 0;
        while(getline(std::cin, line))
        {
            if(line.empty())
            {
                if(!same) std::cout << "YES\n";
                else std::cout << "NO\n";
            }
            else
            {
                inputVec = strToVec(line);
                foo(inputVec);
            }
        }
        --cases;
    }
    return 0;
}