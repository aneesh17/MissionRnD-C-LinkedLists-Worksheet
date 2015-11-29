/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
//typedef struct node Node;

struct node * numberToLinkedList(int number) {
	if (number < 0)
	{
		number *= (-1);
	}
	struct node *head, *Next;
	head = (struct node*)malloc(sizeof(struct node));
	head->num = (number % 10);
	head->next = NULL;	
	for (number/=10; number>0; number /= 10)
	{
		Next = (struct node*)malloc(sizeof(struct node));
		Next->num = number % 10;
		Next->next = head;
		head = Next;
	}
	return(head);
	//return NULL;
}