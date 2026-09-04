#include "sort.h"

/**
 * swap_ints - Swaps two integers and prints the whole array
 *
 * @array: The array holding both integers
 * @size: Number of elements in @array
 * @i: Index of the first integer
 * @j: Index of the second integer
 */
void swap_ints(int *array, size_t size, size_t i, size_t j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
 * sift_down - Restores the max heap property from a given root
 *
 * @array: The array to be sifted
 * @size: Number of elements in @array (used for printing)
 * @root: Index of the node to sift down
 * @limit: Index right after the last element of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t limit)
{
	size_t child, largest;

	while (1)
	{
		child = 2 * root + 1;
		if (child >= limit)
			return;
		largest = child;
		if (child + 1 < limit && array[child + 1] > array[child])
			largest = child + 1;
		if (array[root] >= array[largest])
			return;
		swap_ints(array, size, root, largest);
		root = largest;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the sift-down Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	i = size / 2;
	while (i > 0)
	{
		i--;
		sift_down(array, size, i, size);
	}

	i = size;
	while (i > 1)
	{
		i--;
		swap_ints(array, size, 0, i);
		sift_down(array, size, 0, i);
	}
}
