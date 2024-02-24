#include "sort.h"

/**
 * swap_elements - swaps two integers in an array
 * @first: pointer to the first element
 * @second: pointer to the second element
 */
void swap_elements(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * selection_sort - implements the selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int outer_index = 0, inner_index = 0, min_loc = 0;
	int min_value;

	while (outer_index < size)
	{
		inner_index = outer_index;
		min_value = array[outer_index]; /* Initialize min_value with array[outer_index] */
		min_loc = outer_index;          /* Initialize min_loc with outer_index */

		while (inner_index < size)
		{
			if (array[inner_index] < min_value)
			{
				min_value = array[inner_index];
				min_loc = inner_index;
			}
			inner_index++;
		}

		if (array[outer_index] != array[min_loc])
		{
			swap_elements(array + outer_index, array + min_loc);
			/* print_array(array, size); // Print array if print_array is defined */
		}
		outer_index++;
	}
}
