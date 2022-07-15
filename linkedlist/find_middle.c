// C program to find middle of linked list

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

void print_middle()
{
	S *slow_ptr = head;
	S *fast_ptr = head;

	if (head!=NULL)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}
		printf("\nThe middle element is [%d]\n", slow_ptr->data);
	}
}

void print()
{
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		S *temp=head;
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main()
{
int i,data,n;
printf("Enter the size of linked list: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("Enter data-%d:",i);
	scanf("%d",&data);
	insert(data);
}
printf("\nThe data in 3 nodes of single linked list:\n");
print();
print_middle();

return 0;
}


