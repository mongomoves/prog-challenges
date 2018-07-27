/*
	ID: 706
*/

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#define NUMBER_VEC std::vector<std::vector<char>>
enum ROW_TYPE {CENTER_BAR, LEFT_BAR, RIGHT_BAR, BOTH_BAR, BLANK};


void printNumber(NUMBER_VEC &number, unsigned rowLength)
{
	for (int i = 0; i < number.size(); i++)
	{
		for (int j = 0; j < number[i].size(); j++)
		{
			printf("%c", number[i][j]);
		}
		if ((i + 1) % rowLength == 0) printf("\n");
	}
	/*for (int i = 0; i < number.size(); i++)
	{
		if (number[i][0] == '|' || number[i][number[i].size() - 2] == '|')
		{
			for(int k = 0; k < size; k++)
			{
				for (int j = 0; j < number[i].size(); j++)
				{
					printf("%c", number[i][j]);
				}
				if ((k + 1) % rowLength == 0) {
					//std::cout << (i % rowLength - 1 == 0) << " " << "\n";
					printf("\n");
				}
			}
			if ((i + 1) % rowLength == 0) printf("\n");
		}
		else 
		{
			for (int j = 0; j < number[i].size(); j++)
			{
				printf("%c", number[i][j]);
			}
			if ((i + 1) % rowLength == 0) printf("\n");
		}
	}*/
}

void fill_row(std::vector<char> &row, unsigned size, char filler)
{
	for (int i = 0; i < size; i++)
	{
		row.push_back(filler);
	}
}

std::vector<char> create_row(ROW_TYPE row_type, unsigned size)
{
	std::vector<char> row;
	switch (row_type)
	{
	case CENTER_BAR: // " _ "
		row.push_back(' ');
		fill_row(row, size, '-');
		row.push_back(' ');
		break;
	case LEFT_BAR: // "|  "
		row.push_back('|');
		fill_row(row, size + 1, ' ');
		break;
	case RIGHT_BAR: // "  |"
		fill_row(row, size + 1, ' ');
		row.push_back('|');
		break;
	case BOTH_BAR: // "| |"
		row.push_back('|');
		fill_row(row, size, ' ');
		row.push_back('|');
		break;
	case BLANK: // "   "
		fill_row(row, size + 2, ' ');
		break;
	}
	row.push_back(' ');
	return row;
}

std::vector<int> int_to_array(std::string input)
{
	std::vector<int> numbers;
	for (int i = 0; i < input.length(); i++)
	{
		numbers.push_back(input[i] - '0');
	}
	return numbers;
}

int main()
{
	/*
	std::vector<char> CENTER_LINE = { ' ', '-', ' ' };
	std::vector<char> LEFT_BAR = { '|', ' ', ' ' };
	std::vector<char> RIGHT_BAR = { ' ', ' ', '|' };
	std::vector<char> TWO_BARS = { '|', ' ', '|' };
	std::vector<char> BLANK = { ' ', ' ', ' ' };*/
	
	//NUMBER_VEC ZERO = { CENTER_LINE, TWO_BARS, BLANK, TWO_BARS, CENTER_LINE };
	//NUMBER_VEC ONE = { BLANK, RIGHT_BAR, BLANK, RIGHT_BAR, BLANK };
	//NUMBER_VEC TWO = { CENTER_LINE, RIGHT_BAR, CENTER_LINE, LEFT_BAR, CENTER_LINE };
	//Fylla "endimensionellt", tror det går? Bryt rad när den bläddrat lika många som där är siffror
	//NUMBER_VEC all = { ZERO[0], ONE[0], TWO[0] };

	std::vector<ROW_TYPE> ZERO = { CENTER_BAR, BOTH_BAR, BLANK, BOTH_BAR, CENTER_BAR };
	std::vector<ROW_TYPE> ONE = { BLANK, RIGHT_BAR, BLANK, RIGHT_BAR, BLANK };
	std::vector<ROW_TYPE> TWO = { CENTER_BAR, RIGHT_BAR, CENTER_BAR, LEFT_BAR, CENTER_BAR };

	std::vector<std::vector<ROW_TYPE>> numberFormats = { ZERO, ONE, TWO };
	NUMBER_VEC all;
	unsigned n;
	char s[CHAR_MAX];
	std::vector<int> numbers;
	std::vector<char> row;
	while (scanf("%d %s", &n, &s) > 0)
	{
		if (n == 0) { return 0; }
		numbers = int_to_array(std::string(s));
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < numbers.size(); j++)
			{
				row = create_row(numberFormats[numbers[j]][i], n);
				if (row[0] == '|' || row[row.size() - 2] == '|')
				{
					for (int k = 0; k < n; k++)
					{
						all.push_back(row);
					}
				}
				else
				{
					all.push_back(row);
				}
				//all.push_back(create_row(numberFormats[numbers[j]][i], n));
			}
		}
		printNumber(all, numbers.size());
		all.clear();
	}

	return 0;
}