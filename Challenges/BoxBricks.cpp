/*
    ID: 591
*/

#include <iostream>
#include <vector>

int main()
{
    int set = 1, stacks, stack, bricks, perStack, diff;
    std::vector<int> stacksVec;
    while(std::cin >> stacks)
    {
        if(!stacks) return 0;
        bricks = 0;
        diff = 0;
        for(int i = 0; i < stacks; i++)
        {
            std::cin >> stack;
            stacksVec.push_back(stack);
            bricks += stack;
        }
        perStack = bricks / stacksVec.size();
        for(auto it = stacksVec.begin(); it != stacksVec.end(); ++it)
        {
            if(*it > perStack) diff += *it - perStack;
        }
        std::cout << "Set #" << set << "\n";
        std::cout << "The minimum number of moves is " << diff << "." << "\n" << std::endl;
        ++set;
        stacksVec.clear();

    }
    return 0;
}