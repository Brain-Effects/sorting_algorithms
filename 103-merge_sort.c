#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of array[].
 * @array: The original array to be sorted
 * @left: The left subarray
 * @right: The right subarray
 * @left_size: Number of elements in left
 * @right_size: Number of elements in right
 *
 * Description: The first subarray is array[l..m]
 * The second subarray is array[m+1..r]
 * It assumes that the two subarrays are already sorted and
 * merges them to sort the combined array.
 *
 * Return: void
 */
void merge(int *array, int *left, size_t left_size, int *right,
		size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		array[k++] = left[i++];
		else
		array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;
	left = (int *) malloc(mid * sizeof(int));
	right = (int *) malloc((size - mid) * sizeof(int));

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, mid, right, size - mid);

	free(left);
	free(right);
}
