#include <stdlib.h>
#include <unistd.h>
#include "sort.h"

/**
 * print_number - prints an integer
 * @n: The integer to be printed
 *
 * Return: void
 */
void print_number(int n)
{
	char digit;

	if (n >= 10)
		print_number(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int i, max = 0, *count, *sorted;

	if (!array || size < 2)
		return;

	/* find maximum value in the array */
	for (i = 0; i < (int)size; i++)
	if (array[i] > max)
		max = array[i];

	/* initialize count array with zeros */
	count = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* store count of each element */
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	/* change count[i] so that count[i] now contains actual */
	/* position of this character in output array */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	/* print count array */
	print_array(count, max + 1);

	/* build the output sorted array */
	sorted = malloc(sizeof(int) * size);
	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/* copy the sorted array to original array */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}
