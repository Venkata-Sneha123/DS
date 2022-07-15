// Implement merge sort technique
  
#include <stdio.h>
#define SIZE 10

void merge(int a[],int lb,int mid,int ub)
{
	int i,j,k;
	int n1 = mid-lb+1;
	int n2 = ub-mid;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = a[lb + i];

	for (j = 0; j < n2; j++)
		R[j] = a[mid + 1 + j];

	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = lb; // Initial index of merged subarray

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}


	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}

}

void merge_sort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		merge_sort(a,lb,mid);
		merge_sort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}

}



int main()
{
	int i,n,arr[SIZE];
	printf("Enter size of an array: ");
	scanf("%d",&n);
	printf("Enter an array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	merge_sort(arr,0,n-1);

	printf("Sorted array: \n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
