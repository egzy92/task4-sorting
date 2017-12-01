#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "Equality.h"



int InputArray(const char *FileName, int **m, int *n)
{int I,t,err=0;FILE *f;
 *m=NULL;*n=0;
 for(I=0;I<2;I++)
 {
  if(I==1&&*n>0)
   *m=(int*)malloc(*n*sizeof(int));
  *n=0;
  f=fopen(FileName,"r");
  if(f)
  {
   for(*n=0;fscanf(f,"%d",(I==0?&t:(*m)+(*n)))==1;(*n)++);
  }else {err=-1;break;}
  fclose(f);
 }
 
return err; 
}


int generateArrayForSorting(int **arrayForGeneration, int *arraySize){
	helpArray=(int *)calloc(arraySize,sizeof(int));
}


int checkSortedArray (int **arrayForChecking,int * isSorted){
	
}

int sortArray (int **arrayForSorting, double * timeOfExecution){
	printf("%i",arrayForSorting[0]);
}


