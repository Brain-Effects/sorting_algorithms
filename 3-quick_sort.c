#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements of an array
 * @array: The array
 * @i: The first index
 * @j: The second index
 * @size: The size of the array
 */
void swap(int *array, size_t i, size_t j, size_t size)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
 * partition - Partitions an array using the Lomuto scheme
 * @array: The array
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the array
 * Return: The final index of the pivot
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot;
	size_t i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
	if (array[j] < pivot)
		{
		i++;
		if (i != j)
		swap(array, i, j, size);
		}
	}
	if (array[i + 1] > pivot)
		swap(array, i + 1, high, size);
	return (i + 1);
}

/**
 * quick_sort_helper - Recursively sorts an array using the quick sort algorithm
 * @array: The array
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the array
 */
void quick_sort_helper(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		if (pivot > 0)
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
