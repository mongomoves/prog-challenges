#include <iostream>

int main()
{
    int n, k;
    unsigned long long arr[200][200];
    for(int i = 0; i < 200; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == j || j == 0) arr[i][j] = 1;
            else arr[i][j] = (arr[i-1][j - 1] + arr[i - 1][j]) % 1000000;
        }
    }
    while(std::cin >> n >> k)
    {
        if(!n && !k) return 0;
        std::cout << arr[n + k-1][n] << "\n";
    }
    return 0;
}