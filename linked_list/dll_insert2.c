#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "doubly_linked_list_node.h"

int dll_insert(Node *rootp , int value )
{
	Node *this ;
	Node *next ;
	Node *newnode ;
	for( this = rootp ; ( next = this->fwd ) != NULL ; this = next ) {
		if( next->value == value )
			return 1 ;
		if( next->value > value )
			break;
	}
	newnode = (Node *)malloc( sizeof( Node ));
	if( newnode == NULL )
		return -1;
	newnode->value = value ;

	if( next != NULL ) {
		//并未位于链表结尾
		if( this != rootp ){
			this->fwd = newnode ;
			newnode->fwd = next ;
			newnode->bwd = this ;
			next->bwd = newnode ;
		}
		else {
			rootp->fwd = newnode ;
			newnode->fwd = next;
			newnode->bwd = NULL ;
			next->bwd = newnode ;
		}
	}
	else {
		//位于链表结尾
		if( this != rootp ) {
			this->fwd = newnode;
			newnode->fwd = NULL ;
			newnode->bwd = this ;
			rootp->bwd = newnode;
		}
		else {
			rootp->fwd  = newnode;
			newnode->fwd = NULL ;
			newnode->bwd = NULL ;
			rootp->bwd  = newnode ;
		}
	}
	return 1;
}


