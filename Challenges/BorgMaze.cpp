/*
    ID: 10307
*/

#include <iostream>
#include <vector>
#include <string>




int main()
{
    std::vector<std::vector<char>> maze;
    std::string line;
    int cases; 
    std::cin >> cases;
    while(cases--)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << x << " " << y << "\n";
        getline(std::cin, line); //Getting rid of this line
        for(int i = 0; i < y; i++)
        {
            std::vector<char> row;
            getline(std::cin, line);
            for(char c : line) row.push_back(c);
            maze.push_back(row);
        }



        

        maze.clear();
    }
}