/* WAP to implement insertion sort. */

#include<stdio.h>

void insertion(int a[],int size);

int main()
{
	int size;
	printf("Enter a size of an array: ");
	scanf("%d",&size);

	int i,arr[size];
	printf("Enter an array :\n");

	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	insertion(arr,size);
	return 0;
}

void insertion(int a[],int size)
{
	int i,j,flag,temp;
	for(i=0;i<size;i++)
	{	
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}

	printf("The sorted array is : ");

	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
