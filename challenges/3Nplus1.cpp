/*
	1.6.1: "The 3n + 1 Problem"
	Collatz conjecture: If n is an even number, the next entry is n / 2. If n is an odd number the next
	entry is 3 * n + 1. This is repeated until n is 1.
	Problem is to find the maximum cycle length for amongst all numbers between i and j. Cycle length is the
	number of steps for n to reach 1.
	Print results thusly: i j max
	Guarantee: i and or j is always bigger than zero and smaller than 1 million.
*/

#include <stdio.h>
#include <vector>

void threeNplus1(unsigned i, unsigned j)
{
	//max will be the result, count starts at 1 because i also counts.
	unsigned max = 0, count = 1, l;
	for (int k = i; k <= j; k++)		//loop between i and j
	{
		l = k; //copy k, so we can mess with it
		while (l != 1) 
		{
			if (l % 2 == 0) l = l / 2;	//even number
			else l = 3 * l + 1;			//odd number
			++count;
		}
		if (count > max) max = count;	//set new max if count is bigger
		count = 1;						//reset count to 1 for new iteration
	}
	printf("%d %d %d \n", i, j, max);	//print as part of solution
}

int main()
{
	threeNplus1(1, 10);
	threeNplus1(100, 200);
	threeNplus1(201, 210);
	threeNplus1(900, 1000);
	return 0;
}