#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcFibonacci(int positiveInteger);

int main()
{
	int number = 1;
    int fibonacci = calcFibonacci(number);
	
	printf("Fibonacci of %d is %d", number, fibonacci);
    return 0;
}

int calcFibonacci(int positiveInteger)
{
	int fibonacci;

	if (positiveInteger == 0)
		fibonacci = 0;
	else if (positiveInteger == 1)
		fibonacci = 1;
	else
	{
		int prevFibonacci = 0;
		int currentFibonacci = 1;
		int n = 1;
		
		while (n < positiveInteger)
		{
			fibonacci = prevFibonacci + currentFibonacci;
			prevFibonacci = currentFibonacci;
			currentFibonacci = fibonacci;
			n++;
		}
	}
	
	return fibonacci;
}