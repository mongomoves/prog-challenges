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
#include <stdio.h>

int main()
{
	std::vector<double> expenses;
	int students, dollar, cent, total, exchange;
	while (scanf("%d", &students) > 0)
	{
		if (students == 0) return 0;
		exchange = 0;
		total = 0;
		for (int i = 0; i < students; i++)
		{
			scanf("%d.%d", &dollar, &cent);
			expenses.push_back((dollar * 100) + cent);
			total += (dollar * 100) + cent;
		}
		double each = double(total) / students;
		for (auto it = expenses.begin(); it != expenses.end(); ++it)
		{
			if (*it > each) exchange += ((*it) - each);
		}
		dollar = exchange / 100;
		cent = exchange % 100;
		double sum = double(dollar) + (double(cent) / 100);
		printf("$%.2f\n", sum);
		expenses.clear();
	}
	return 0;
}