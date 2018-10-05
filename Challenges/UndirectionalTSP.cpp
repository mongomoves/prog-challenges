/**
 * ID: 116
 */

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
    int rows, cols;
    std::vector<std::vector<int>> matrix;
    while(std::cin >> rows >> cols)
    {
        //Input for a case
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
        //Set the last column in the costmat as the same as the input.
        //It is the starting point and wont change
        for(int i = 0;  i < rows; i++) 
        {
            costmat[i][cols - 1] = matrix[i][cols - 1];
        }
        //Typical dp minimum path cost thingy, but bottom-up.
        for(int i = cols - 2; i >= 0; i--)
        {
            for(int j = 0; j < rows; j++)
            {
                costmat[j][i] = min(
                    costmat[(j - 1 + rows) % rows][i + 1],
                    costmat[j][i + 1],
                    costmat[(j + 1 + rows) % rows][i + 1]
                ) + matrix[j][i];
            }
        }
        int lowestCost = INT32_MAX;
        int lowRow = 0;
        //Find the minimum cost path value from the first column
        for(int i = 0; i < rows; i++)
        {
            if(costmat[i][0] < lowestCost) 
            {
                lowestCost = costmat[i][0];
                lowRow = i;
            }
        }
        std::cout << lowRow + 1;    //First row to print is the one with the lowest value
        //Find the rest of the rows of the path
        for(int i = 0; i < cols - 1; i++)
        {
            int lowcost = costmat[(lowRow + -1 +rows) % rows][i + 1];
            int row = (lowRow + -1 + rows) % rows;
            //Already checked -1 now do 0 and 1.
            for(int j = 0; j <= 1; j++)
            {
                int rowut = (lowRow + j + rows) % rows; //Row value that can wrap around
                if(costmat[rowut][i + 1] < lowcost)
                {
                    lowcost = costmat[rowut][i + 1];
                    row = rowut;
                }
                //This is the lexicographical thingy. If the value is the same but the row "value"
                //is lower then that row is the one to go with
                if(costmat[rowut][i + 1] == lowcost && rowut < row)
                {
                    row = rowut;
                }
            }
            lowRow = row;
            std::cout << " " << lowRow + 1;
        }
        std::cout << "\n";
        std::cout << lowestCost << "\n";
        matrix.clear();
    }
    return 0;
}