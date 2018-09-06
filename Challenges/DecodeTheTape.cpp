/*
    ID: 10878
*/

#include <iostream>
#include <string>

int main()
{
    int character;            
    std::string line;
    while(getline(std::cin, line))
    {
        character = 0;
        int j = 7;
        for(std::size_t i = 1; i < line.length() - 1; i++)
        {
            if(line[i] == '.') continue;
            if(line[i] == 'o')
            {
                int intChar = 1 << j;
                character += intChar;
            }
            --j;
        }
        if(character) std::cout << char(character);
        std::cout.flush();
    }
    return 0;
}