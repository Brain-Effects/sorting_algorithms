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
 * partition - partitions the array for quicksort
 * @arr: array to be partitioned
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: the partition index
 */
int partition (int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
		i++;
		swap(arr, i, j, size);
		}
	}
	swap(arr, i + 1, high, size);
	return (i + 1);
}

/**
 * quickSort - implements the quicksort algorithm
 * @arr: array to be sorted
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: Number of elements in the array
 */
void quickSort(int arr[], int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, size);

		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
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
	quickSort(array, 0, size - 1, size);
}
