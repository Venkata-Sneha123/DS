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
enque(4);
enque(5);
enque(6);
display();
deque();
deque();
deque();
deque();
deque();
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
if(front == rear+1)
{
    printf("queue is empty\n");
    rear=-1;
    return;
}
else
{
    if(front <=rear)
    {
      printf("deleted element = %d\n",q[front]);
     front++;
    }
   
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


/*

output:
Inserted elements = 1
Inserted elements = 2
Inserted elements = 3
Inserted elements = 4
Inserted elements = 5
queue is full
Elements in queue are:
1
2
3
4
5
deleted element = 1
deleted element = 2
deleted element = 3
deleted element = 4
deleted element = 5
queue is empty
queue is empty

*/
