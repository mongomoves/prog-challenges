/*
	1.6.2 Minesweeper
	Input is an amount of fields. A field starts with two numbers, n and m, being the number
	of rows and columns for the field. 0 < n, m <= 100. This is followed by n amount of lines
	representing the rows, each being m characters long. Safe squares are a . and a mine is 
	a *. Input is terminated by n = m = 0.
	The problem is to print each field, replacing each . with the number of adjacent squares 
	containing a mine.

	ID: 10189
*/

#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

void printField(std::vector<std::vector<int>> &field, unsigned n, unsigned m, unsigned count)
{
	unsigned mines;
	std::cout << "Field #" << count << ":\n";
	for (unsigned i = 0; i < n; i++) //Iterate over entire field
	{
		for (unsigned j = 0; j < m; j++) //Iterate over one line in field
		{
			mines = 0;
			if (field[i][j] == 1) //If mines, then print a mine
			{
				std::cout << "*";
			}
			else //Else check for neighbouring mines.
			{
				//For the same line
				if (j > 0) if (field[i][j - 1] == 1) ++mines;
				if (j < m - 1) if (field[i][j + 1] == 1) ++mines;
				//For the line above
				if (i != 0)
				{
					if (j > 0) if (field[i - 1][j - 1] == 1) ++mines;
					if (field[i - 1][j] == 1) ++mines;
					if (j < m - 1) if (field[i - 1][j + 1] == 1) ++mines;
				}
				//For the line below
				if (i < n - 1)
				{
					if (j > 0) if (field[i + 1][j - 1] == 1) ++mines;
					if (field[i + 1][j] == 1) ++mines;
					if (j < m - 1) if (field[i + 1][j + 1] == 1) ++mines;
				}
				std::cout << mines;
			}
		}
		std::cout << "\n";
	}
}

int main()
{
	const int MAX = 100;
	std::vector<std::vector<int>> field;
	std::string line;
	unsigned n, m = 0, count = 1;
	while (scanf("%d %d\n", &n, &m) > 0)
	{
		if (n == 0 || m == 0) return 0;
		if (n <= MAX && m <= MAX)
		{
			for (unsigned i = 0; i < n; i++)
			{
				std::vector<int> row(m, 0);
				getline(std::cin, line);
				for (unsigned j = 0; j < m; j++)
				{
					if (line[j] == '*') row[j] = 1;
				}
				field.push_back(row);
				row.clear();
			}
			printField(field, n, m, count);
			field.clear();
			++count;
		}
		std::cout << "\n";
	}
	return 0;
}