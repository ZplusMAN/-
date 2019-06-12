/*
 * 在有序的单链表中查找一个值, 并返回该值所在节点的地址
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "sll_node.h"

Node *search(Node *linkp ,  int new_value )
{
	Node *current ;
	current = linkp ;
	while( current != NULL ){
		if( current->value < new_value ) {
			current = current->link;
		}
		else if( current->value == new_value ){
			return current;
		}
	}
}



