#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}S;

S *head=NULL;


S* insert(int data)
{

	S* new=(S*)malloc(sizeof(S));
	if(new==NULL)
	{
		printf("Memory is not allocated\n");
		return 0;
	}
	new->data=data;
	new->link=NULL;
	if(head==NULL)
		head=new;
	else
	{
		S* temp=head;
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=new;
	}

}


S* display()
{
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		S* temp=head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("\n\n");
	}
}


S* insert_at_beg(int data)
{
	S* new=(S*)malloc(sizeof(S));
	if(new==NULL)
	{
		printf("Memory is not allocated\n");
		return 0;
	}
	new->data=data;
	new->link=NULL;

	if(head==NULL)
		head=new;
	else
	{
		new->link=head;
		head=new;
		//return head;
	}

}

S* insert_at_end(int data)
{
	S* new=(S*)malloc(sizeof(S));
	if(new==NULL)
	{
		printf("Memory is not allocated\n");
		return 0;
	}
	new->data=data;
	new->link=NULL;
	
	if(head==NULL)
		head=new;
	else
	{
		S* temp=head;
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=new;
	}

}

int find_middle()
{
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		S* fast=head;
		S* slow=head;
		
		while(fast!=NULL && fast->link!=NULL)
		{
			fast=fast->link->link;
			slow=slow->link;
		}

		printf("Middle node = %d\n",slow->data);
		int r=slow->data;
		return r;
	}
}

S* insert_at_middle(int data)
{

	S* new=(S*)malloc(sizeof(S));
	if(new==NULL)
	{
		printf("Memory is not allocated\n");
		return 0;
	}
	new->data=data;
	new->link=NULL;
	
	if(head==NULL)
		head=new;
	else
	{
		int r=find_middle();
		S* temp=head;
		while(temp->data!=r)
			temp=temp->link;
		new->link=temp->link;
		temp->link=new;

	}
}

S* insert_at_pos(int data,int pos)
{
	int c=1;
	S* new=(S*)malloc(sizeof(S));
	if(new==NULL)
	{
		printf("Memory is not allocated\n");
		return 0;
	}
	new->data=data;
	new->link=NULL;
	
	if(head==NULL)
		head=new;
	else
	{
		S* temp=head;
		while(c!=pos)
		{
			temp=temp->link;
			c++;
		}

		new->link=temp->link;
		temp->link=new;

	}



}

S* delete_at_beg()
{
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		S* temp=head;
		head=temp->link;
		free(temp);
	}
}

S* delete_at_end()
{
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		S* temp=head;
		while(temp->link->link!=NULL)
			temp=temp->link;
		free(temp->link);
		temp->link=NULL;
	}
}


S* delete_middle()
{
	if(head==NULL)
		printf("List is empty\n");
	if(head->link==NULL)
		free(head);
	else
	{
		int r=find_middle();
		S* temp=head;
		S* prev=head;

		while(temp->data!=r)
		{
			prev=temp;
			temp=temp->link;
		}
		prev->link=temp->link;
		free(temp);
	}
}



S* delete_at_pos(int pos)
{
	int c=1;

	if(head==NULL)
		printf("List is empty\n");
	else
	{
		S* temp=head;
		S* prev=head;
		while(c!=pos)
		{
			prev=temp;
			temp=temp->link;
			c++;
		}
		prev->link=temp->link;
		free(temp);
	}
}

int count_nodes()
{
	int count=0;
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		S* temp=head;
		while(temp!=NULL)
		{
			temp=temp->link;
			count++;
		}
	}
	return count;
}



int main()
{
	int size,data,choice,pos;
	printf("Enter number of nodes:");
	scanf("%d",&size);
	for(int i=0;i<size;i++)
	{
		printf("Enter data-%d:",i+1);
		scanf("%d",&data);
		insert(data);
	}

	while(1)
	{
		printf("\n1.Insert at beginning\n2.Insert at End\n3.Insert at middle node\n4.Insert at pos\n5.Delete at beginning\n"
				"6.Delete at end\n7.Delete middle node\n8.find middle\n9.Delete at pos\n10.print the list\n11.count number of nodes\nEnter your choice:");
	
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				insert_at_beg(data);
				break;
			case 2:
				printf("Enter data:");
				scanf("%d",&data);
				insert_at_end(data);
				break;


			case 3:
				printf("Enter data:");
				scanf("%d",&data);
				insert_at_middle(data);
				break;
			case 4:
				printf("Enter data:");
				scanf("%d",&data);
				printf("Enter position:");
				scanf("%d",&pos);
				insert_at_pos(data,pos);
				break;
			case 5:
				delete_at_beg();
				break;
			case 6:
				delete_at_end();
				break;
			case 7:
				delete_middle();
				break;
			case 8:
				find_middle();
				break;
			case 9:
				printf("Enter position:");
				scanf("%d",&pos);
				delete_at_pos(pos);
				break;
			case 10:	
				display();
				break;
			case 11:
				int r=count_nodes();	
				printf("Number of nodes = %d\n",r);
				break;
			default:
				exit(0);
		}	

	}
	return 0;
}

