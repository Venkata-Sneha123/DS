//1.  Create a stack in linked list i.e. push operation, pop operation and peek operation  

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *link;
}s;

int push(s **top_arg, int ndata)
{
	s *new = malloc(sizeof(s));
	if(new == NULL)
	{
		printf("Memory is not allocated\n");
	}
	else
	{
		new->data = ndata;
		new->link = NULL;
		if(*top_arg == NULL)
		{
			*top_arg = new;
		}
		else
		{
			new->link=*top_arg;
			*top_arg = new;
		}
		printf("Inserted element is : %d\n",new->data);
	}
}

int pop(s **top)
{
	if(*top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		s *temp = *top;
		*top = temp->link;
		printf("Deleted element is : %d\n",temp->data);
		free(temp);
	}
}

void peek(s **top)
{
	if(*top == NULL)
	{
		printf("Stack is empty\n");
	}
	s *temp = *top;
	printf("Topmost element is :%d\n",temp->data);

}

int display(s **top)
{
	if(*top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Stack elements are: ");
		s *temp = *top;
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
}

int main()
{
s *top=NULL;
push(&top,10);
push(&top,20);
push(&top,30);
peek(&top);
display(&top);
pop(&top);
pop(&top);
pop(&top);
display(&top);
return 0;
}
