#include<stdio.h>
#define N 100

void bubble_sort(int a[],int);

int main()
{
	int a[N],i,n;
	printf("Enter size of an array:");
	scanf("%d",&n);
	printf("Enter elements in an array: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble_sort(a,n);
	return 0;
}

void bubble_sort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}	
		}
	}
	printf("After bubble sorting elements in an array: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

