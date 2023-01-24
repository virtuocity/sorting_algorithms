#include "sort.h"

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
    unsigned int i;
    unsigned int j;
    
    if (!array || !size || size == 1)
    {
        return;
    }
    
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            int temp = 0;
            if (array[j] > array[j + 1])
            {
                /*swap the elements of array*/
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
            }
            
        }
    }
}