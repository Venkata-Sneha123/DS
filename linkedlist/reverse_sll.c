/* WAP to reverse the linked list. */

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


void reverse()
{
	S *prev=NULL;
	S *current = head;
	S *next=NULL;
	while(current != NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}

int main()
{
int size,data,i;
printf("Enter size of list:");
scanf("%d",&size);
for(i=0;i<size;i++)
{
	printf("Enter data-%d:",i);
	scanf("%d",&data);
	insert(data);
}
printf("Before reversing the linked list: ");
print();
reverse();

printf("After reversing the linked list: ");
print();
return 0;
}
