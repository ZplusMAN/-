/*
 * 删除一个有序单链表中的节点
 */
#include <stdio.h>
#include <stdlib.h>
#include "sll_node.h"

#define TRUE 1
#define FALSE 0

int  delete( Node **linkp , int delete_value )
{
	Node *current ;
	while( ( current = *linkp )!= NULL && current->value < delete_value ){
		linkp = &current->link;
	}
	if( delete_value == current->value ){
		(*linkp)->link = current->link;
		return TRUE ;
	} 
	else {
		return FALSE ;
	}
}


