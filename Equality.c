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


int searchArray (int * array,int elementsCount)
{
	int i,k,m,a=0;
	int answer;
	int * answerArray,* isElementLocalMin, *numberOfPoints;
	int minElement,localMinRow=0;
	int * helpArray;
	int currentPointNumber,currentPoint;
	int * resultArray;
	helpArray=(int *)calloc(elementsCount,sizeof(int));
	minElement=array[0];
	//Проверка является ли первый элемент массива частью множественного локального минимума
	if (elementsCount>1)
	{
		if(array[0]==array[1])
			a=1;
	}
	//Поиск локальных минимумов со второго элемента до предпоследнего
	for(i=1;i<elementsCount-1;i++)
	{
		if(array[i]<array[i-1])
			a=1;
		if(array[i]==array[i-1])
			a++;
		if(array[i]>array[i-1]&&(a>0))
		{
			for (k=0;k<a;k++)
				helpArray[i-1-k]=1;
			a=0;
		}
		
		if(array[i]>array[i-1])
		{
			a=0;
		}
		if(minElement>array[i])
			minElement=array[i];
	}
	//Проверка является ли последний элемент массива частью множественного локального минимума
	if (elementsCount>1)
	{
		if((array[elementsCount-1]==array[elementsCount-2])&&(a>0))
		{
			a++;
			for (k=0;k<a;k++)
				helpArray[elementsCount-1-k]=1;
			a=0;
		}
	}
	//Проверка является ли первый и последний элементы массива единичными локальными минимумами
	if (elementsCount>1){
		if(array[0]<array[1])
			helpArray[0]=1;
		
		if(array[elementsCount-1]<array[elementsCount-2])
			helpArray[elementsCount-1]=1;
		
		if(array[elementsCount-1]<minElement)
			minElement=array[elementsCount-1];
	}
	//Поиск количества элементов, которые будут исключены из результирующего массива
	for (i=1;i<elementsCount;i++)
	{
		if((helpArray[i]==1)&&(helpArray[i-1]==1))
			localMinRow++;
	}
	//Инициализация и заполнение результирующего массива
	answer=elementsCount-localMinRow;
	answerArray=(int *)malloc((elementsCount-localMinRow)*sizeof(int));
	numberOfPoints=(int *)malloc((elementsCount-localMinRow)*sizeof(int));
	isElementLocalMin=(int *)malloc((elementsCount-localMinRow)*sizeof(int));
	k=0;
	for(i=0;i<elementsCount;i++)
	{
		if(helpArray[i]==0)
		{
			isElementLocalMin[k]=0;
			numberOfPoints[k]=1;
			answerArray[k]=array[i];
			k++;
		}
		if((helpArray[i]==1)&&(helpArray[i-1]!=1))
		{
			isElementLocalMin[k]=1;
			numberOfPoints[k]=1;
			answerArray[k]=array[i];
			k++;
		}
		
		if((helpArray[i]==1)&&(helpArray[i-1]==1))
		{
			numberOfPoints[k-1]++;
		}
	}
	//Вывод результирующего массива
	printf("Answer array:\n");
	for(i=0;i<answer;i++){
		printf("%i ",answerArray[i]);
	}
	printf("\n");
	//Вывод результирующего массива
	printf("Local min:\n");
	for(i=0;i<answer;i++){
		printf("%i ",isElementLocalMin[i]);
	}
	printf("\n");
	//Вывод результирующего массива
	printf("Number of points:\n");
	for(i=0;i<answer;i++){
		printf("%i ",numberOfPoints[i]);
	}
	printf("\n");
	
	i=0;
	while(i<answer)
	{
		if (isElementLocalMin[i]==1)
		{
			if (i!=(answer-1))
			{
				for(k=(i+1);k<answer;k++)
				{
					if (isElementLocalMin[k]==1)
					{
						currentPoint=answerArray[i];
						currentPointNumber=numberOfPoints[i];
						answerArray[i]=answerArray[k];
						numberOfPoints[i]=numberOfPoints[k];
						answerArray[k]=currentPoint;
						numberOfPoints[k]=currentPointNumber;
						i=k;
						break;
					}
				}
			}
		}
		i++;
	}
	
	
	//Вывод результирующего массива
	printf("Answer array:\n");
	for(i=0;i<answer;i++){
		printf("%i ",answerArray[i]);
	}
	printf("\n");
	//Вывод результирующего массива
	printf("Local min:\n");
	for(i=0;i<answer;i++){
		printf("%i ",isElementLocalMin[i]);
	}
	printf("\n");
	//Вывод результирующего массива
	printf("Number of points:\n");
	for(i=0;i<answer;i++){
		printf("%i ",numberOfPoints[i]);
	}
	printf("\n");
	
	
	m=0;
	resultArray=(int *)malloc(elementsCount*sizeof(int));
	i=0;
	while(i<elementsCount)
	{
		for(k=0; k<numberOfPoints[m];k++)
		{
			resultArray[i]=answerArray[m];
			i++;
		}
		m++;
	}
	
	//Вывод результирующего массива
	printf("Result array:\n");
	for(i=0;i<elementsCount;i++){
		printf("%i ", resultArray[i]);
	}
	printf("\n");
	
	return answer;
}


