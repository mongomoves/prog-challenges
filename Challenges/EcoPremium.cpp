#include <iostream>
#include <math.h>
int main()
{
    int cases, farmers, land, animals, ecodegree;
    long cost;
    std::cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        cost = 0;
        std::cin >> farmers;
        for(int j = 0; j < farmers; j++)
        {
            std::cin >> land >> animals >> ecodegree;
            cost += round((((double)land / animals) * ecodegree) * animals);
        }
        std::cout << cost << std::endl;
    }
    return 0;
}