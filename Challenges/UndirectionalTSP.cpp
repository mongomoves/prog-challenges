#include <iostream>
#include <vector>
#include <limits>

int min(int x, int y, int z) 
{ 
   if (x < y) 
      return (x < z)? x : z; 
   else
      return (y < z)? y : z; 
} 

int main()
{
    int rows, cols, cost;
    std::vector<std::vector<int>> matrix;
    //std::vector<int> path;
    while(std::cin >> rows >> cols)
    {
        for(int i = 0; i < rows; i++)
        {
            std::vector<int> row;
            for(int j = 0; j < cols; j++)
            {
                int val;
                std::cin >> val;
                row.push_back(val);
            }
            matrix.push_back(row);
        }
        int costmat[10][100] = {0};
        std::vector<int> path;
        for(int i = 0;  i < rows; i++) costmat[i][cols - 1] = matrix[i][cols - 1];
        int bound;
        for(int i = cols - 2; i >= 0; i--)
        {
            for(int j = 0; j < rows; j++)
            {
                cost = INT32_MAX;
                for(int k = -1; k <= 1; k++)
                {   
                    bound = (j + k + rows) % rows;
                    if(costmat[bound][i + 1] < cost)
                    {
                        cost = costmat[bound][i + 1];
                    }
                    costmat[j][i] = matrix[j][i] + cost;
                }
            }
        }

        // for(int i = 0; i < rows; i++)
        // {
        //     for(int j = 0; j < cols; j++)
        //     {
        //         std::cout << costmat[i][j] << " ";
        //     }
        //     std::cout << "\n";
        // }
        // std::cout << "\n";
  
        
        matrix.clear();
    }
    return 0;
}