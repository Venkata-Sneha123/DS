//4. Implement queue using arrays  

#include<stdio.h>
#define S 5

int front=-1;
int rear=-1;
int q[S];
void enque(int );
void deque();
void display();

int main()
{
enque(1);
enque(2);
enque(3);
display();
deque();
display();
return 0;
}

void enque(int ele)
{
if(rear == S-1)
{
	printf("queue is full\n");
	return;
}
else
{
	if(front==-1)
		front=0;
	rear++;
	q[rear]=ele;
	printf("Inserted elements = %d\n",q[rear]);
}
}

void deque()
{
if(front == -1)
{
	printf("queue is empty\n");
	return;
}
else
{
	printf("deleted element = %d\n",q[front]);
	front++;
}
}
void display()
{
if(rear==-1)
{
	printf("queue is empty\n");
}
else
{
	int i=front;
	printf("Elements in queue are:\n");
	for(;i<=rear;i++)
		printf("%d\n",q[i]);
}
}

