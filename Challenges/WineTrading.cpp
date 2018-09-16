/*
    ID: 11054
*/

#include <iostream>

int main()
{
    int citizens, diff;
    long long sum;
    while(std::cin >> citizens)
    {
        if(!citizens) return 0;
        sum = diff = 0;
        while(citizens--)
        {
            int house;
            std::cin >> house;
            diff += house;
            sum += abs(diff);
        }
        std::cout << sum << "\n";
    }
    return 0;
}