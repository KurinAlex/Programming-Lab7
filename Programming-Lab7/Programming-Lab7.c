#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_MIN_BOUND (-100.0)
#define RAND_MAX_BOUND 100.0
#define SCALE ((RAND_MAX_BOUND - RAND_MIN_BOUND) / RAND_MAX)

int main()
{
	srand(time(NULL));

	int n;
	printf("Enter n: ");
	scanf_s("%d", &n);

	double* a = (double*)calloc(n, sizeof(double));

	printf("a: ");
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() * SCALE + RAND_MIN_BOUND;
		printf("%lf ", a[i]);
	}
	printf("\n");

	int pair_count = 0;

	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] > 0.0 && a[i] > 0.0)
		{
			pair_count++;
		}
	}

	printf("Number of pairs of neighbour positive numbers: %d", pair_count);

	free(a);

	getch();
	return 0;
}