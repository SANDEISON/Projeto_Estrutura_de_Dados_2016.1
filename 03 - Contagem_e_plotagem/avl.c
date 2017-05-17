/*avl.c*/

#include <stdio.h>
#include <stdlib.h>
#include "cp.h"

 struct AVL
{
    int value;
    struct AVL*  left;
    struct AVL*  right;
    int      height;
};


 int searchAVL(int value, AVL *tree, int *comparacoes)
 {
	 if (tree != NULL && tree->value != value)
	 {
		 *comparacoes += 1;
		 if( value < tree->value )
			 searchAVL( value, tree->left, comparacoes);
		 else
			 searchAVL( value, tree->right, comparacoes);
	 }
     return *comparacoes;
 }

 int h( AVL* tree )
 {
     if( tree == NULL )
         return -1;
     else
         return tree->height;
 }

 int max( int l, int r)
 {
     return l > r ? l: r;
 }

 AVL* single_rotate_with_left( AVL* k2 )
 {
     AVL *k1 = NULL;

     k1 = k2->left;
     k2->left = k1->right;
     k1->right = k2;

     k2->height = max( h( k2->left ), h( k2->right ) ) + 1;
     k1->height = max( h( k1->left ), k2->height ) + 1;
     return k1; /* new root */
 }

 AVL* single_rotate_with_right( AVL* k1 )
 {
     AVL* k2;

     k2 = k1->right;
     k1->right = k2->left;
     k2->left = k1;

     k1->height = max( h( k1->left ), h( k1->right ) ) + 1;
     k2->height = max( h( k2->right ), k1->height ) + 1;

     return k2;  /* New root */
 }

  AVL* double_rotate_with_left( AVL* k3 )
 {
     /* Rotate between k1 and k2 */
     k3->left = single_rotate_with_right( k3->left );

     /* Rotate between K3 and k2 */
     return single_rotate_with_left( k3 );
 }



  AVL* double_rotate_with_right( AVL* k1 )
 {
     /* rotate between K3 and k2 */
     k1->right = single_rotate_with_left( k1->right );

     /* rotate between k1 and k2 */
     return single_rotate_with_right( k1 );
 }

 /*
     insert a new node into the tree
 */
 AVL* insert(int value, AVL* tree )
 {
     if( tree == NULL )
     {
         /* Create and return a one-node tree */
         tree = (AVL*)malloc(sizeof(AVL));
         if( tree == NULL )
         {
             fprintf (stderr, "ERRO de memoria!!! (AVL func insert)\n");
             exit(1);
         }
         else
         {
             tree->value = value;
             tree->height = 0;
             tree->left = tree->right = NULL;
         }
     }
     else if( value <= tree->value )
     {
         tree->left = insert( value, tree->left );
         if( h( tree->left ) - h( tree->right ) == 2 )
         {
             if( value <= tree->left->value )
                 tree = single_rotate_with_left( tree );
             else
                 tree = double_rotate_with_left( tree );
         }
     }
     else if( value > tree->value )
     {
         tree->right = insert( value, tree->right );
         if( h( tree->right ) - h( tree->left ) == 2 )
         {
             if( value > tree->right->value )
                 tree = single_rotate_with_right( tree );
             else
                 tree = double_rotate_with_right( tree );
         }
     }

     tree->height = max( h( tree->left ), h( tree->right ) ) + 1;
     return tree;
 }

 void printAVL(AVL *tree)
 {
 	if (tree != NULL) {

 		  printf ("(%d ", tree->value);
 	      printAVL (tree->left);
 	      printAVL (tree->right);
 	      printf(") ");
 	   }
 	else
 	{
 		printf("() ");
 	}
 }





