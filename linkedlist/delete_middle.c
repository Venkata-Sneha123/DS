// delete middle node in sll.

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;          
	struct node *next; 
} *head;


void createList(int n);
void deleteMiddleNode(int position);
void displayList();
int count_nodes();



int main()
{
	int n, position,result;
	printf("Enter the total number of nodes: ");
	scanf("%d", &n);
	createList(n);

	printf("\nData in the list \n");
	displayList();
	result=count_nodes();
	printf("\nTotal Number of nodes in the linked list are = %d\n",result);
	position=result/2;


	deleteMiddleNode(position); //  Delete middle node from list 

	printf("\nData in the list \n");
	displayList();

	return 0;
}


void createList(int n) // Create a list of n nodes
{
	struct node *newNode, *temp;
	int data, i;

	head = (struct node *)malloc(sizeof(struct node));

	if(head == NULL) // If unable to allocate memory for head node
	{
		printf("Unable to allocate memory.");
	}
	else
	{
		printf("Enter the data of node 1: "); // Read data of node from the user
		scanf("%d", &data);

		head->data = data; // Link the data field with data
		head->next = NULL; // Link the address field to NULL

		temp = head;
		for(i=2; i<=n; i++) // Create n nodes and adds to linked list
		{
			newNode = (struct node *)malloc(sizeof(struct node));

			/* If memory is not allocated for newNode */
			if(newNode == NULL)
			{
				printf("Unable to allocate memory.");
				break;
			}
			else
			{
				printf("Enter the data of node %d: ", i);
				scanf("%d", &data);

				newNode->data = data; // Link the data field of newNode with data
				newNode->next = NULL; // Link the address field of newNode with NULL

				temp->next = newNode; // Link previous node i.e. temp to the newNode
				temp = temp->next;
			}
		}

		printf("Singly Linked list created successfully\n");
	}
}



int count_nodes() // count number of nodes
{
	struct node *new=head;
	int count = 0;
	while (new != NULL) {
		new = new->next;
		count++;
	}
	return count;
}



void deleteMiddleNode(int position) // Delete middle node of the linked list
{
	int i;
	struct node *toDelete, *prevNode;

	if(head == NULL)
	{
		printf("List is already empty.");
	}
	else
	{
		toDelete = head;
		prevNode = head;

		for(i=1; i<=position; i++)
		{
			prevNode = toDelete;
			toDelete = toDelete->next;

			if(toDelete == NULL)
				break;
		}

		if(toDelete != NULL)
		{
			if(toDelete == head)
				head = head->next;

			prevNode->next = toDelete->next;
			toDelete->next = NULL;

			/* Delete nth node */
			free(toDelete);

			printf("\nSuccessfully deleted node from middle of list\n");
		}
		else
		{
			printf("Invalid position unable to delete.");
		}
	}
}


void displayList() // Display entire list
{
	struct node *temp;
	if(head == NULL)
	{
		printf("List is empty.");
	}
	else
	{
		temp = head;
		while(temp != NULL)
		{
			printf("Data = %d\n", temp->data); // Print the data of current node
			temp = temp->next;                 // Move to next node
		}
	}
}


