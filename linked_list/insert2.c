#include <stdio.h>
#include <stdlib.h>
#include "sll_node.h"

#define FALSE 0
#define TRUE 1

int sll_insert(Node ** rootp, int value )
{
	Node *previous ;
	Node *current ;
	Node *new ;

	current = *rootp ;
	previous = NULL ;
	while( current != NULL && current->value < value ){
		previous = current;
		current = current->link;
	}

	new = (Node *)malloc( sizeof( Node ));
	if( new == NULL )
		return FALSE;
	new->value = value ;

	new->link = current ;
	if( previous == NULL )
		*rootp = new ;
	else
		previous->link = new ;

	return TRUE ;
}

