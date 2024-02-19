#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - Compares and swaps elements in a bitonic sequence
 * @array: The array
 * @i: The first index
 * @j: The second index
 * @size: The size of the array
 * @dir: The direction of sorting (1 for up, 0 for down)
 */
void bitonic_compare(int *array, size_t i, size_t j, size_t size, int dir)
{
    int tmp;

    if (dir == (array[i] > array[j]))
    {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        print_array(array, size);
    }
}

/**
 * bitonic_merge - Merges two bitonic sequences in a given direction
 * @array: The array
 * @low: The lowest index of the sequence
 * @count: The number of elements in the sequence
 * @size: The size of the array
 * @dir: The direction of sorting (1 for up, 0 for down)
 */
void bitonic_merge(int *array, size_t low, size_t count, size_t size, int dir)
{
    size_t i, k;

    if (count > 1)
    {
        k = count / 2;
        for (i = low; i < low + k; i++)
            bitonic_compare(array, i, i + k, size, dir);
        bitonic_merge(array, low, k, size, dir);
        bitonic_merge(array, low + k, k, size, dir);
    }
}

/**
 * bitonic_sort_helper - Recursively sorts a bitonic sequence in a given direction
 * @array: The array
 * @low: The lowest index of the sequence
 * @count: The number of elements in the sequence
 * @size: The size of the array
 * @dir: The direction of sorting (1 for up, 0 for down)
 */
void bitonic_sort_helper(int *array, size_t low, size_t count, size_t size, int dir)
{
    size_t k;

    if (count > 1)
    {
        k = count / 2;
        printf("Merging [%lu/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
        print_array(array + low, count);
        bitonic_sort_helper(array, low, k, size, 1);
        bitonic_sort_helper(array, low + k, k, size, 0);
        bitonic_merge(array, low, count, size, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    bitonic_sort_helper(array, 0, size, size, 1);
}
