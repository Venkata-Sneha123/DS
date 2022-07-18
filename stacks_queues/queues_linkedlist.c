//3. Write C program Implemenet a Queue using single linked list 

#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}queue;

void enqueue(int ,queue **,queue **);
void dequeue(queue **,queue **);
void front_element(queue **,queue **);
void Display(queue **,queue **);

int main()
{
    queue *front=NULL;
    queue *rear=NULL;
    enqueue(10,&front,&rear);
    enqueue(20,&front,&rear);
    enqueue(30,&front,&rear);
    Display(&front,&rear);
    front_element(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    Display(&front,&rear);
    dequeue(&front,&rear);
    Display(&front,&rear);
    return 0;
}

void enqueue(int n,queue **front_arg,queue **rear_arg)
{
    queue *new=(queue *)malloc(sizeof(queue));
    if(new==NULL)
    {
        printf("memory is not allocated\n");
    }
    else
    {
        new->data=n;
        new->link=NULL;
        if(*front_arg==NULL && *rear_arg==NULL)
        {
            *front_arg=new;
            *rear_arg=new;
        }
        else
        {
           (*rear_arg)->link=new;
            *rear_arg=new;
        }
        printf("The Enqueued element is %d\n",(*rear_arg)->data);
    }
}

void front_element(queue **front_arg,queue **rear_arg)
{
    if(*front_arg==NULL && *rear_arg==NULL)
    {
        printf("Queue is empty\n");
    }  
    else
    {
        printf("the Front element in a queue: %d\n",(*front_arg)->data);    
    }
}

void dequeue(queue **front_arg,queue **rear_arg)
{
    queue *temp=NULL;
    if(*front_arg==NULL && *rear_arg==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp=*front_arg;
        *front_arg=temp->link;
        printf("Dequeued element: %d\n",temp->data);
        free(temp);
    }
}

void Display(queue **front_arg,queue **rear_arg)
{
    queue *temp=NULL;
    temp=*front_arg;
    if(*front_arg==NULL && *rear_arg==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->link;
            if(temp!=NULL)
            {
                printf("<--");
            }
        }
        printf("\n");
    }
}
