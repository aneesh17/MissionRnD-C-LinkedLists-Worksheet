/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node Node;

struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;

	Node *currentNode, *nextNode, *prevNode, *endOfList = NULL, *temp;

	while (endOfList != head->next)
	{
		prevNode = head;
		currentNode = head;
		nextNode = currentNode->next;
		while (currentNode != endOfList)
		{
			if (currentNode->num > nextNode->num)
			{
				if (currentNode == head)
				{
					temp = nextNode->next;
					nextNode->next = currentNode;
					currentNode->next = temp;
					head = nextNode;
					prevNode = nextNode;
				}

				else
				{
					temp = nextNode->next;
					nextNode->next = currentNode;
					currentNode->next = temp;
					prevNode->next = nextNode;
					prevNode = nextNode;
				}
			}

			else
			{
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
			nextNode = currentNode->next;
			if (nextNode == endOfList)
			{
				endOfList = currentNode;
			}
		}
	}
	return(head);
}