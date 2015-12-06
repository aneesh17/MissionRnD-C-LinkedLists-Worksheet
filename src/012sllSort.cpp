/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	int numOfZero = 0, numOfOne = 0, numOfTwo = 0;
	struct node* temp = head;
	while (temp->next != NULL)
	{
		if (temp->data == 0)
			numOfZero++;
		else if (temp->data == 1)
			numOfOne++;
		else
			numOfTwo++;
		temp = temp->next;
	}
	if (temp->data == 0)
		numOfZero++;
	else if (temp->data == 1)
		numOfOne++;
	else
		numOfTwo++;

	while (numOfZero > 0)
	{
		head->data = 0;
		head = head->next;
		numOfZero--;
	}
	while (numOfOne > 0)
	{
		head->data = 1;
		head = head->next;
		numOfOne--;
	}
	while (numOfTwo > 0)
	{
		head->data = 2;
		head = head->next;
		numOfTwo--;
	}	
}