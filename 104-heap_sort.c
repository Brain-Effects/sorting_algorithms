#include <stdio.h>
#include "sort.h"

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
 * sift_down - Sifts down an element in a heap
 * @array: The array
 * @start: The start index of the heap
 * @end: The end index of the heap
 * @size: The size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root, left, right, largest;

    root = start;
    while (root * 2 + 1 <= end)
    {
        left = root * 2 + 1;
        right = root * 2 + 2;
        largest = root;
        if (array[largest] < array[left])
            largest = left;
        if (right <= end && array[largest] < array[right])
            largest = right;
        if (largest == root)
            return;
        else
        {
            swap(array, root, largest, size);
            root = largest;
        }
    }
}

/**
 * heapify - Builds a max heap from an array
 * @array: The array
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
    size_t start;

    start = (size - 2) / 2;
    while (1)
    {
        sift_down(array, start, size - 1, size);
        if (start == 0)
            break;
        start--;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t end;

    if (array == NULL || size < 2)
        return;
    heapify(array, size);
    end = size - 1;
    while (end > 0)
    {
        swap(array, 0, end, size);
        end--;
        sift_down(array, 0, end, size);
    }
}
