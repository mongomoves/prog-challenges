/*
    ID: 185
*/

#include <iostream>
#include <string>


int value(char r)
{
    int res = -1;
    switch(r)
    {
        case 'I': res = 1;
        break;
        case 'V': res = 5;
        break;
        case 'X': res = 10;
        break;
        case 'L': res = 50;
        break;
        case 'C': res = 100;
        break;
        case 'D': res = 500;
        break;
        case 'M': res = 1000; 
    }
    return res;
}

int rToD(std::string &str)
{
    int res = 0;
    for(size_t i = 0; i < str.length(); ++i)
    {
        int s1 = value(str[i]);
        if(i + 1 < str.length())
        {
            int s2 = value(str[i+1]);
            if(s1 >= s2) res = res + s1;
            else 
            {
                res = res + s2 - s1;
                i++;
            }
        }
        else 
        {
            res = res + s1;
            i++;
        }
    }
    return res;
}

int main()
{
    std::string str;
    while(std::cin >> str)
    {
        if(str == "#") return 0;
        size_t pluspos = str.find("+");
        size_t eqpos = str.find("=");
        std::string part1 = str.substr(0, pluspos);
        std::string part2 = str.substr(pluspos + 1, eqpos - pluspos - 1);
        std::string part3 = str.substr(eqpos + 1);
        //std::cout << rToD(part1) << " + " << rToD(part2) << " = " << rToD(part3) << "\n";
        if(rToD(part1) + rToD(part2) == rToD(part3)) std::cout << "Correct";
        else std::cout << "Incorrect";

        //if(part1.size() + part2.size() > part3.size()) std::cout << " impossible";

        std::cout << "\n";

    }


    return 0;
}