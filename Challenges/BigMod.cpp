/*
    ID: 374
*/

#include <math.h>
#include <iostream>


int modexp(int x, int y, int n)
{
    if(!y) return 1;
    long z = modexp(x, floor(y / 2), n);
    if(y % 2 == 0) return (z * z) % n;
    else return x * (z * z) % n;
}

int main()
{
    int b, p, m;
    while(std::cin >> b >> p >> m)
    {
        std::cout << modexp(b, p, m) << "\n";
    }
}