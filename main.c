#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "Equality.h"

int main(void)
{
	int err=0,elementsCount;
	int *arrayForSorting;
	int isSorted;
	double timeOfExecution;
	err=InputArray("data.txt", &arrayForSorting, &elementsCount);
	err=InputArray(&arrayForSorting, &timeOfExecution);
	return err;
}
