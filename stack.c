#include<stdio.h>
#define S 7

int stack[S];

int tos=-1;
void push(int );
void pop();
void display();
void getmin();

int main()
{
push(1);
push(2);
push(3);
push(4);
push(5);
push(6);
push(7);
display();
pop();
display();
pop();
display();
}

void push(int ele)
{
if(tos == S-1)
{
	printf("Stack is full\n");
	return;
}
else
{
	tos++;
	stack[tos]=ele;
	printf("Inserted elements = %d\n",stack[tos]);
}
}

void pop()
{
if(tos == -1)
{
	printf("Stack is empty\n");
	return;
}
else
{
	printf("poped element = %d\n",stack[tos]);
	tos--;
}
getmin(tos);
} 


void getmin()
{
int i,min=tos;
if(tos == -1)
{
	printf("Stack is empty\n");
	return;
}
else
{
	for(i=0;i<=tos;i++)
	{
		if(stack[i]<min)
			min=stack[i];
	}
	printf("min element = %d\n",min);
	
}

}

void display()
{
if(tos == -1)
{
	printf("Stack is empty\n");
	return;
}
int i;
printf("Elements in stack:\n");
for(i=0;i<=tos;i++)
	printf("%d\n",stack[i]);
}

