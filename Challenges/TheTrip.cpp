/*
	1.6.3 The Trip
	A number of students agree to share expenses from a trip evenly.
	The problem is to figure out, after given the number of students and expenses,
	how to equalize (within one cent) the expenditure amongst all students.
	No more than 1000 students, no one spends more than $10 000.00.
	Input is one line with a positive integer, denoting the number of students. Followed
	by the same number of lines showing expenses for a student, in dollar and cents.
	Output is one line stating the total amount in dollars and cents that needs to be exchanged
	for the costs to be equalised.

	ID: 10137
*/


#include <vector>
#include <string>

void theTrip(std::vector<std::string> &input)
{
	double sum, each, exchange;
	int students;
	std::vector<double> expenditure;
	for (auto it = input.begin(); it != input.end(); ++it)
	{
		sum = 0.0;
		each = 0.0;
		exchange = 0.0;
		expenditure.clear();
		if (std::stoi(*it) == 0) break;
		else if ((*it).find(".") == std::string::npos)
		{
			students = std::stoi(*it++);
		}
		for (int i = 0; i < students; i++)
		{
			expenditure.push_back(std::stod(*it));
			sum += std::stod(*it);
			if (i < students - 1) ++it;
		}
		each = roundf((sum / students) * 100) / 100;
		for (auto it = expenditure.begin(); it != expenditure.end(); ++it)
		{
			if (*it > each) exchange += ((*it) - each);
		}
		printf("$%.2f \n", exchange);
	}
}

int main()
{
	std::vector<std::string> input;
	char line[CHAR_MAX];
	while (fgets(line, CHAR_MAX, stdin))
	{
		input.push_back(line);
	}
	theTrip(input);
	return 0;
}