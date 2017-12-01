#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "Equality.h"

int main(void)
{
 int err=0,countOfElements=0;
 int *array;
 int answer;
 err=InputArray("data.txt", &array, &countOfElements);
 if(err!=0)
  printf("Error!!!\n");
 else
  {
	if (countOfElements==0){
		printf("File is empty!!!");
	} else {
		answer=searchArray(array,countOfElements);
		printf("Number of elements in new array: %i",answer);
	}
  }
return err;
}
