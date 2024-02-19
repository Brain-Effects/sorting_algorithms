#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: double pointer to the head of the list
 * @node1: first node
 * @node2: second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next != NULL)
	node2->next->prev = node1;
	node2->prev = node1->prev;
	node2->next = node1;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
	*list = node2;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: double pointer to the head of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (list == NULL || *list == NULL)
	return;

	current = *list;
	while (swapped)
	{
	swapped = 0;
	while (current->next != NULL)
	{
		if (current->n > current->next->n)
		{
		swap_nodes(list, current, current->next);
		swapped = 1;
		print_list((const listint_t *)*list);
		}
	else
		current = current->next;
	}
	if (!swapped)
		break;
	swapped = 0;
	while (current->prev != NULL)
		{
		if (current->n < current->prev->n)
		{
		swap_nodes(list, current->prev, current);
		swapped = 1;
		print_list((const listint_t *)*list);
		}
	else
		current = current->prev;
		}
	}
}
