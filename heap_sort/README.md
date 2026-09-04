# Heap sort

Sorting an array of integers in ascending order with the sift-down Heap sort
algorithm.

## Files

| File | Description |
| --- | --- |
| `sort.h` | Header file holding the prototypes of `heap_sort` and `print_array` |
| `0-heap_sort.c` | Implementation of `void heap_sort(int *array, size_t size);` |
| `0-O` | Time complexity of Heap sort: best, average and worst case |

## How it works

The array is first turned into a max heap by sifting down every internal node,
starting from the last one. Then the root, which holds the largest value, is
swapped with the last element of the heap, the heap size is reduced by one and
the new root is sifted down. The array is printed after every swap.

## Compilation

```
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o heap
```
