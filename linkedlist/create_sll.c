// single linked list creation.

#include<stdio.h>
#include<stdlib.h>

typedef struct stu
{
	int data;
	struct stu *next;
}S;



void insert(S **head,int data)
{
	S *temp=NULL;
	S *new=malloc(sizeof(S));
	if(new==NULL)
		printf("Memory is not allocated\n");
	else
	{
		new->data=data;
		new->next=NULL;
		if(*head==NULL)
		{
			*head=new;
		}
		else
		{
			temp=*head;
			while(temp->next != NULL)
			{
				temp=temp->next;
			}
			temp->next=new;
		}	
	}
}


void print(S **head)
{
	if(*head==NULL)
		printf("list is empty\n");
	else
	{
		S *temp=*head;
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
int i,data,size;
S *head=NULL;
printf("Enter the size of linked list: ");
scanf("%d",&size);
for(i=0;i<size;i++)
{
	printf("Enter data:");
	scanf("%d",&data);
	insert(&head,data);
}
printf("The data in single linked list:\n");
print(&head);
return 0;
}
