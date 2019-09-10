#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;

}Node;

void traverselist(Node* n){
	printf("Linked list is : ");
    while(n!= NULL){
        printf("%d ",n->data);
        n=n->next;
    }
    printf("\n");
}

/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data)
{

    /* 1. allocate node */
   Node* new_node = (Node*) malloc(sizeof(Node));

    /* 2. put in the data */
   new_node->data = new_data;


    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

   /* 4. move the head to point to the new node */
   (*head_ref) = new_node;
}

/* Insert node after a specific given node */
void insertafter(Node* prevNode ,int new_data){

    /*Check if the previous Node is NULL*/
    if(prevNode==NULL){
        printf("Operation not possible.Previous Node cannot be NULL");
        return;
    }


    /* 1. allocate node */
   Node* new_node = (Node*) malloc(sizeof(Node));

    /* 2. put in the data */
   new_node->data=new_data;

   /*3. New Node next takes the value of the next from the previous */
   new_node->next=prevNode->next;

   /*4.Link previous node to the new one*/
   prevNode->next=new_node;

}

void append(Node** head_ref , int new_data){
    /*Check if the previous Node is NULL*/

    /* 1. allocate node */
   Node* new_node = (Node*) malloc(sizeof(Node));

   Node *last= *head_ref;

    /* 2. put in the data */
   new_node->data=new_data;

    /* 3. link the new_node to NULL*/
   new_node->next=NULL;

   /* 4. If the Linked List is empty, then make the new node as head */
    if (head_ref == NULL)
    {
    *head_ref = new_node;
    return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL){
        last = last->next;
    }

    /* 6. Change the next of last node */
    last->next = new_node;

    return;
}

int main(){

	Node *head=NULL;

	int option=0,data=0;

	while(1){
		printf("1.Push\n");
		printf("2.InsertAfter\n");
		printf("3.Append\n");

		printf("Chose Option : \n");
		scanf("%d",&option);

		printf("Insert Data of the node : \n");
		scanf("%d",&data);

		switch(option){
			case 1:push(&head,data);
				   traverselist(head);
				   break;

			case 2:insertafter(head,data); //to be re-thinked how pointer is going to be dinamically called.
				   traverselist(head);
				   break;

			case 3:append(&head,data);
				   traverselist(head);
				   break;

			default: break;

		}

		if(option == 4)
		{
			break;
		}

	}

//	 Node* head=NULL;
//	 Node* second=NULL;
//	 Node* third=NULL;
//
//
//	head=( Node*)malloc(sizeof( Node));
//	second=( Node*)malloc(sizeof( Node));
//	third=( Node*)malloc(sizeof( Node));
//
//	head->data=2;
//	head->next=second;
//
//	second->data=3;
//	second->next=third;
//
//	third->data=4;
//	third->next=NULL;
//
//	traverselist(head);
//	printf("\n");
//	push(&head,1);
//
//	traverselist(head);

    return 0;
}
