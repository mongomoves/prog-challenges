/*
	1.6.2 Minesweeper
	Input is an amount of fields. A field starts with two numbers, n and m, being the number
	of rows and columns for the field. 0 < n, m <= 100. This is followed by n amount of lines
	representing the rows, each being m characters long. Safe squares are a . and a mine is 
	a *. Field is terminated by n = m = 0.
	The problem is to print each field, replacing each . with the number of adjacent squares 
	containing a mine.
*/

/*
	This solution is flawed, and can probably be broken. It uses a one-dimensional vector instead
	of messing about with multid. Unclear if this is a good or bad idea.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void readFile(std::vector<std::string> &lines, std::string filename)
{
	std::ifstream fstr(filename);
	std::string line;
	while (getline(fstr, line))
	{
		lines.push_back(line);
	}
}

//n and m being passed is the rows and columns for the field, keeping the iterations in check.
void printField(int itIndex, int n, int m, std::vector<std::string> &lines, unsigned count)
{
	std::cout << "Field #" << count << ":" << std::endl;
	for (int i = itIndex; i <= (itIndex + n) - 1; i++) //Iterate over all lines for the field
	{
		for (int j = 0; j < m; j++) //Iterate over one line in a field
		{
			int mines = 0;
			if (lines.at(i)[j] == '*') //Just print a mine if it's a mine
			{
				std::cout << '*';
			}
			else if (lines.at(i)[j] == '.') //If not a mine, count surrounding mines
			{
				//For the same line
				if (j > 0) if (lines.at(i)[j - 1] == '*') ++mines;
				if (j < lines.at(i).length()) if (lines.at(i)[j + 1] == '*') ++mines;
				//For the line above
				if (i != itIndex)
				{
					if (j > 0) if (lines.at(i - 1)[j - 1] == '*') ++mines;
					if (lines.at(i - 1)[j] == '*') ++mines;
					if (j < lines.at(i - 1).length()) if (lines.at(i - 1)[j + 1] == '*') ++mines;
				}
				//For the line below
				if (i < (itIndex + n) - 1)
				{
					if (j > 0) if (lines.at(i + 1)[j - 1] == '*') ++mines;
					if (lines.at(i + 1)[j] == '*') ++mines;
					if (j < lines.at(i + 1).length()) if (lines.at(i + 1)[j + 1] == '*') ++mines;
				}
				std::cout << mines; //Print the number of adjacent mines, replacing the dot from the input
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void minesweeper(std::string file)
{
	std::vector<std::string> lines;
	readFile(lines, file);
	unsigned count = 1;
	for (auto it = lines.begin(); it != lines.end(); ++it)
	{
		if ((*it).length() == 3 && (*it).at(0) > 48) //If "n" is 0 program should terminate. 
		{
			printField(it - lines.begin() + 1, (*it).at(0) - '0', (*it).at(2) - '0', lines, count);
			++count;
		}
	}
}

int main()
{
	minesweeper("mines.txt");
	return 0;
}