/*cp.c*/
#include <stdio.h>
#include <stdlib.h>
#include "cp.h"

struct BinaryTree {
      int  value;
      struct BinaryTree *left;
      struct BinaryTree *right;
   };

Binarytree* createNewNode(int value)
{
    Binarytree *newNode;
    newNode = (Binarytree*) malloc (sizeof(Binarytree));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Binarytree* insertNode(Binarytree *bt, Binarytree *newNode)
{

	if(bt == NULL) return newNode;
	if(bt->value > newNode->value)
	{
		bt->left = insertNode(bt->left, newNode);
	}
	else
	{
		bt->right = insertNode(bt->right, newNode);
	}

	return bt;
}

void printBinaryTree(Binarytree *bt)
{
	if (bt != NULL) {

		  printf ("(%d ", bt->value);
	      printBinaryTree (bt->left);
	      printBinaryTree (bt->right);
	      printf(") ");
	   }
	else
	{
		printf("() ");
	}
}

int searchNode (Binarytree *bt, int value, int *x)
{
    if (bt != NULL && bt->value != value)
    {
    	*x += 1;
    	if (bt->value > value)
    		 searchNode (bt->left, value, x);
    	else
    	 searchNode (bt->right, value, x);

    }

   return *x;
}
