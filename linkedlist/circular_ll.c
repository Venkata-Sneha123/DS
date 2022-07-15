/*
Create a circular LL with 5 nodes having char data - vowels - a,e,i,o,u
*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct stu
{
	char data;
	struct stu *next;
}S;

S *head=NULL;

void insert(char data)
{
	S *new=malloc(sizeof(S));
	if(new==NULL)
		printf("Memory is not allocated\n");
	else
	{
		new->data = data;
		new->next = new;
		if (head == NULL) 
		{
			head = new;
	        }

	        else 
		{
			new->data = data;
			new->next = head->next;
			head->next = new;
			head = new;
		}
	}
}


void print()
{
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		S *temp;
		temp = head->next;
		char ch;
		ch=temp->data;
		do {
			printf("%c->",temp->data);
			temp = temp->next;
		} while (temp != head->next);
		printf("%c",ch);
	}
	printf("\n");
}

int main()
{
int i;
char data;
for(i=0;i<SIZE;i++)
{
	printf("Enter data-%d:",i);
	scanf("\n%c",&data);
	insert(data);
}
printf("The circular linked list is :\n");
print();
return 0;
}



