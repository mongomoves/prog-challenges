/*
    ID: 839
*/

#include <iostream>
#include <string>

bool same;

int foo()
{
    int wl, dl, wr, dr;
    int left, right;
    std::cin >> wl >> dl >> wr >> dr;
    left = wl;
    right = wr;
    if(!wl)
    {
        left = foo();
    }
    if(!wr)
    {
        right = foo();
    }
    //std::cout << "l * dl: " << l * dl << " r * dr: " << r * dr << "\n";
    if(left * dl != right * dr) same = false;
    return left + right;
}

int main()
{    
    int cases;
    std::string line;
    std::cin >> cases;
    getline(std::cin, line); //Get rid of first blank line
    while(cases--)
    {
        same = true;
        while(getline(std::cin, line))
        {
            foo();
            if(line.empty()) break;
        }
        if(same) std::cout << "YES\n";
        else std::cout << "NO\n";
        if(cases) std::cout << "\n";
    }
    return 0;
}