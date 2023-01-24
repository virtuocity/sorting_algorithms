#include "sort.h"

/**
 * min - search for snallest element
 * @array: The array to search
 * @size: Number of elements in @array
 *
 * Return: address of the minimum item of the array
 */
int *min(int *array, size_t size)
{
    int *minimum = &array[0];

    while (size--)
    {
        if (array[size] < *minimum)
        {
            minimum = &array[size];
        }
    }

    return (minimum);
}

/**
 * selection_sort - sort array using selection sort
 * algo
 * 
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
    size_t i;

    if (!array || size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        int *mini = min(&array[i], size - i);
        int temp = 0;

        if (&array[i] != mini)
        {
            temp = array[i];

            array[i] = *mini;
            *mini = temp;

            print_array(array, size);
        }
    }
}