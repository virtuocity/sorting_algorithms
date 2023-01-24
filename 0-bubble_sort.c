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
 * bubble_sort - sort an array using bubble sort
 * algo
 * 
 * @array: array to sort
 * @size: size of array
 * Return: void , just print each iteration of sorting
 */
void bubble_sort(int *array, size_t size)
{
    unsigned int i, j;
    
    if (!array || !size || size == 1)
    {
        return;
    }
    
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                /*swap the elements of array*/
                swap(&array[j], &array[j+ 1]);
                print_array(array, size);
            }
            
        }
    }
}