/* list.c */
#include <stdlib.h>
#include <stdio.h>
#include "cp.h"

struct node
{
    int item;
    struct node *nextNode;
};

Node* createLinkedList()
{
    return NULL;
}

int isEmpty(Node *first)
{
    return(first == NULL);
}

Node* insertNodeList(Node *first, int item)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->item = item;
    newNode->nextNode = first;
    return newNode;
}

void printLinkedList(Node *first)
{
    Node *p;
    for(p = first; p != NULL; p = p->nextNode)
    {
        printf("%d ", p->item);
    }
}

int search(Node *first, int item)
{
	int x = 0;
	while (first != NULL)
	{
		x++;
		if (first->item == item)  return x;
		first = first->nextNode;
    }
	return x;
}

