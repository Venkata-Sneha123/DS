/* WAP to print even nodes of linked list . */

#include<stdio.h>
#include<stdlib.h>

typedef struct stu
{
	int data;
	struct stu *next;
}S;

S *head=NULL;

void insert(int data)
{
	S *temp=NULL;
	S *new=malloc(sizeof(S));
	if(new==NULL)
		printf("Memory is not allocated\n");
	else
	{
		new->data=data;
		new->next=NULL;
		if(head==NULL)
		{
			head=new;
		}
		else
		{
			temp=head;
			while(temp->next != NULL)
			{
				temp=temp->next;
			}
			temp->next=new;
		}	
	}
}


void print_even()
{
	S *temp=NULL;
	int count=1;
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		temp=head;
		while(temp != NULL)
		{
			if(count % 2 == 0)  // for odd nodes printing (count % 2 != 0)
			{
				printf("%d ",temp->data);
			}
			count++;
			temp=temp->next;
		}
		printf("\n");
	}
}

int main()
{
int size,data,i;
printf("Enter size of list:");
scanf("%d",&size);
for(i=0;i<size;i++)
{
	printf("Enter data-%d:",i+1);
	scanf("%d",&data);
	insert(data);
}
print_even();
return 0;
}


