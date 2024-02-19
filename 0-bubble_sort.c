#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	/* Loop through all elements */
	for (i = 0; i < size - 1; i++)
	{
		/* Last i elements are already in place */
		for (j = 0; j < size - i - 1; j++)
		{
		/* Swap if the element found is greater than  next element */
		if (array[j] > array[j + 1])
		{
		temp = array[j];
		array[j] = array[j + 1];
		array[j + 1] = temp;

		/* Print the array after each swap */
		print_array(array, size);
		}
		}
	}
}
