#include "sort.h"

/**
 * swap - swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * Return: Nothing.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @arr: An array of integers to be sorted.
 * @len: Length of the array.
 * Return: Nothing.
 */
void bubble_sort(int *arr, size_t len)
{
    size_t i, j;

    if (arr == NULL || len == 0)
        return;

    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                print_array(arr, len);
            }
        }
    }
}

