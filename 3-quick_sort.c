#include "sort.h"

/**
 * custom_swap - swaps two integers in an array
 * @first_element: pointer to the first element
 * @second_element: pointer to the second element
 */
void custom_swap(int *first_element, int *second_element)
{
	int temp = *first_element;
	*first_element = *second_element;
	*second_element = temp;
}

/**
 * custom_partition - partitions the array using Lomuto scheme
 * @arr: input array
 * @left_index: index of the first element
 * @right_index: index of the last element
 * @size: size of the array
 * Return: integer representing the pivot position
 */
int custom_partition(int *arr, int left_index, int right_index, size_t size)
{
	int pivot_value;
	int i = left_index;

	pivot_value = arr[right_index];

	for (int j = left_index; j < right_index; j++)
	{
		if (arr[j] <= pivot_value)
		{
			custom_swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
			i++;
		}
	}

	custom_swap(&arr[i], &arr[right_index]);
	if (i != right_index)
	{
		print_array(arr, size);
	}

	return i;
}

/**
 * quick_sort_array - sorts the array using QuickSort algorithm
 * @arr: input array
 * @left_index: index of the first element
 * @right_index: index of the last element
 * @size: size of the array
 */
void quick_sort_array(int *arr, int left_index, int right_index, size_t size)
{
	int pivot;

	if (left_index < right_index)
	{
		pivot = custom_partition(arr, left_index, right_index, size);
		quick_sort_array(arr, left_index, pivot - 1, size);
		quick_sort_array(arr, pivot + 1, right_index, size);
	}
}

/**
 * quick_sort - sorts an array using QuickSort algorithm
 * @array: input array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	quick_sort_array(array, 0, size - 1, size);
}
