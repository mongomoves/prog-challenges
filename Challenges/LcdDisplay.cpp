/*
	ID: 706
*/

#include <stdio.h>
#include <vector>
#include <string>
#include <limits>

#define NUMBER_VEC std::vector<std::vector<char>>
enum ROW_TYPE {CENTER_BAR, LEFT_BAR, RIGHT_BAR, BOTH_BAR, BLANK};

//Prints the rows in the vectors, and line breaks everytime it's done the same as the number of digits.
void printNumber(std::vector<NUMBER_VEC> &numbers, int rowLength, int size)
{
	for (int i = 0; i < 2 * size + 3; i++)
	{
		for (std::size_t j = 0; j < numbers.size(); j++)
		{
			for (std::size_t k = 0; k < numbers.at(j).at(i).size(); k++)
			{
				printf("%c", numbers.at(j).at(i).at(k));
			}
			if(j < numbers.size() - 1) printf("%c",' ');
			if ((j + 1) % rowLength == 0) printf("\n");
		}
	}
}

//Fills a row with filler stuff.
void fill_row(std::vector<char> &row, int size, char filler)
{
	for (int i = 0; i < size; i++)
	{
		row.push_back(filler);
	}
}

//Creates a row of the enum type. Size says how much filler is needded for blanks and '-'.
std::vector<char> create_row(ROW_TYPE row_type, int size)
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
	return row;
}

//Just to put digits from string into an int array
std::vector<int> int_to_array(std::string input)
{
	std::vector<int> numbers;
	for (std::size_t i = 0; i < input.length(); i++)
	{
		numbers.push_back(input[i] - '0');
	}
	return numbers;
}

int main()
{
	const int MAX_NUMBER_LENGTH = std::numeric_limits<char>::max();
	//The design of the various digits.
	std::vector<ROW_TYPE> ZERO = { CENTER_BAR, BOTH_BAR, BLANK, BOTH_BAR, CENTER_BAR };
	std::vector<ROW_TYPE> ONE = { BLANK, RIGHT_BAR, BLANK, RIGHT_BAR, BLANK };
	std::vector<ROW_TYPE> TWO = { CENTER_BAR, RIGHT_BAR, CENTER_BAR, LEFT_BAR, CENTER_BAR };
	std::vector<ROW_TYPE> THREE = { CENTER_BAR, RIGHT_BAR, CENTER_BAR, RIGHT_BAR, CENTER_BAR };
	std::vector<ROW_TYPE> FOUR = { BLANK, BOTH_BAR, CENTER_BAR, RIGHT_BAR, BLANK };
	std::vector<ROW_TYPE> FIVE = { CENTER_BAR, LEFT_BAR, CENTER_BAR, RIGHT_BAR, CENTER_BAR };
	std::vector<ROW_TYPE> SIX = { CENTER_BAR, LEFT_BAR, CENTER_BAR, BOTH_BAR, CENTER_BAR };
	std::vector<ROW_TYPE> SEVEN = { CENTER_BAR, RIGHT_BAR, BLANK, RIGHT_BAR, BLANK };
	std::vector<ROW_TYPE> EIGHT = { CENTER_BAR, BOTH_BAR, CENTER_BAR, BOTH_BAR, CENTER_BAR };
	std::vector<ROW_TYPE> NINE = { CENTER_BAR, BOTH_BAR, CENTER_BAR, RIGHT_BAR, CENTER_BAR };
	//Vector for getting a digit design, where index is the digit
	std::vector<std::vector<ROW_TYPE>> numberFormats = {
		ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };

	NUMBER_VEC number;						//2d vector, to hold a digit
	int s;								    //From input, size of output
	char n[MAX_NUMBER_LENGTH];				//From input, the number
	std::vector<int> numbers;				//Vector for the individual numbers in the input
	std::vector<char> row;					//One row in a digit, ex. CENTER_BAR
	std::vector<NUMBER_VEC> allNumbers;		//All the digits to be outputted
	//Scanning for input
	while (scanf("%d %s", &s, n) > 0)
	{
		if (s == 0) { return 0; }					//If end of input
		if(s > 10) continue;
		numbers = int_to_array(std::string(n));
		for (std::size_t i = 0; i < numbers.size(); i++)	//Create each number
		{
			for (int j = 0; j < 5; j++)				//We know the original digit design is only size 5.
			{
				row = create_row(numberFormats[numbers[i]][j], s);
				if (row[0] == '|' || row[row.size() - 1] == '|')	//Need as many of these blocks as the size
				{
					for (int k = 0; k < s; k++)
					{
						number.push_back(row);
					}
				}
				else number.push_back(row);	//No sidebars, we only need one
			}
			allNumbers.push_back(number);
			number.clear();
		}
		printNumber(allNumbers, numbers.size(), s);
		allNumbers.clear();
		printf("\n");
	}
	return 0;
}
