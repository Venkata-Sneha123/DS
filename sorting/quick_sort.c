// Implement quick sort technique
  
#include <stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x=*y;
	*y=temp;
}

int partition(int a[], int lb,int ub)
{
	int pivot=a[lb];
	int start =lb;
	int end=ub;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(&a[start],&a[end]);
		}
	}
	swap(&a[lb],&a[end]);
	return end;
}

void quick_sort(int arr[], int lower_bound,int upper_bound)
{
	int loc;
	if(lower_bound<upper_bound)
	{
		loc=partition(arr,lower_bound,upper_bound);	
		quick_sort(arr,lower_bound,loc-1);
		quick_sort(arr,loc+1,upper_bound);
	}
}

int main()
{
	int size;
	printf("Enter size of an array: ");
	scanf("%d",&size);
	int i,arr[size];
	printf("Enter an array:\n");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);

	quick_sort(arr,0,size-1);

	printf("Sorted array: \n");
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}

