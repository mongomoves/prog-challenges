/*
	1.6.1: "The 3n + 1 Problem"
	Collatz conjecture: If n is an even number, the next entry is n / 2. If n is an odd number the next
	entry is 3 * n + 1. This is repeated until n is 1.
	Problem is to find the maximum cycle length for amongst all numbers between i and j. Cycle length is the
	number of steps for n to reach 1.
	Print results thusly: i j max
	Guarantee: i and or j is always bigger than zero and smaller than 1 million.

	ID: 100
*/

#include <stdio.h>
#include <utility>

const unsigned MAX = 1000000;

unsigned threeNplus1(unsigned i, unsigned j)
{
	if (i > j) std::swap(i, j); //in case someone decides to input in wrong order
	//max will be the result, count starts at 1 because i also counts.
	unsigned max = 0, count, n;
	for (int k = i; k <= j; k++)		//loop between i and j
	{
		n = k;							//copy k, so we can mess with it
		count = 1;						//reset count to 1 for new iteration
		while (n != 1) 
		{
			if (n % 2 == 0) { n = n / 2; }	//even number
			else { n = 3 * n + 1; }			//odd number
			++count;
		}
		if (count > max) max = count;	//set new max if count is bigger
	}
	return max;
}

int main()
{
	unsigned i, j;
	while (scanf("%u %u\n", &i, &j) != EOF)
	{
		if(i < MAX && j < MAX) printf("%d %d %d\n", i, j, threeNplus1(i, j));
	}
	return 0;
}