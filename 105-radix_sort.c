#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Gets the maximum element in an array
 * @array: The array
 * @size: The size of the array
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}
	return (max);
}

/**
 * count_sort - Sorts an array by the digit represented by exp
 * @array: The array
 * @size: The size of the array
 * @exp: The exponent of 10 that represents the digit to sort by
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output, *count;
	size_t i;
	int digit;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	count = malloc(sizeof(int) * 10);
	if (count == NULL)
	{
		free(output);
		return;
	}
	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		output[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	print_array(array, size);
	free(output);
	free(count);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;
	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
		count_sort(array, size, exp);
}
