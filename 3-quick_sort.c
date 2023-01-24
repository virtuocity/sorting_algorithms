#include "sort.h"

/**
 * swap - a utility function to swap two elements
 *
 * @a: first element
 * @b: second element
 * Return: void
 */
void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * partition - place pivot and swap items
 *
 * @array: input array
 * @low: low index to the left
 * @high: high index to the right
 * @size: size of array
 * Return: int which is pivot
 */
int partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[high];
    ssize_t j = low, i;

    for (i = low; i < high; i++)
    {
        if (array[i] < pivot)
        {
            if (j != i)
            {
                swap(&array[j], &array[i]);
                print_array(array, size);
            }

            j++;
        }
    }

    if (high != j && array[high] != array[j])
    {
        swap(&array[high], &array[j]);
        print_array(array, size);
    }

    return (j);
}

/**
 * quicksort - recursive quicksort function with extra
 * parameters
 *
 * @array - input array
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: void
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        int pivot = partition(array, low, high, size);

        quicksort(array, low, pivot - 1, size);
        quicksort(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - quick sort algo
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}