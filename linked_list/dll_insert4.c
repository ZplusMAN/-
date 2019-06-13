#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "doubly_linked_list_node.h"

int dll_insert( register Node *rootp , int value )
{
	register Node *this ;
	register Node *next ;
	register Node *newnode ;
	for( this = rootp ; ( next = this->fwd ) != NULL ;this = next ){
		if( next->value == value )
			return -1;
		if( next->value > value )
			break;
	}

	newnode = (Node *)malloc( sizeof( Node ) );
	if( newnode == NULL )
		return -1;
	newnode->value = value;

	newnode->fwd = next ;
	this->bwd = newnode ;
	if( this != rootp )
		newnode->bwd = this ;
	else 
		newnode->bwd = NULL ;
	if( next != NULL )
		next->bwd = newnode ;
	else 
		rootp->bwd = newnode ;

	return 1;
}

