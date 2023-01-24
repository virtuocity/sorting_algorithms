#include "sort.h"

/**
 * swap_one - swap node pointers of DLL
 * @tprev: previous node
 * @tnext: next node
 * Return: void
 */
void swap_one(listint_t *tprev, listint_t *tnext)
{
    if (tprev->prev)
        tprev->prev->next = tnext;
    if (tnext->next)
        tnext->next->prev = tprev;
    tprev->next = tnext->next;
    tnext->prev = tprev->prev;
    tprev->prev = tnext;
    tnext->next = tprev;
}

/**
 * swap_two - swap node pointers of DLL
 * @tnext: previous node
 * @tprev: next node
 * Return: void
 */
void swap_two(listint_t *tnext, listint_t *tprev)
{

    if (tnext->prev)
        tnext->prev->next = tprev;
    if (tprev->next)
        tprev->next->prev = tnext;
    tnext->next = tprev->next;
    tprev->prev = tnext->prev;
    tnext->prev = tprev;
    tprev->next = tnext;
}

/**
 * swap_three - swap node pointers of DLL
 * @tnext: prev node
 * @tprev: next node
 * @list: head liked list
 * Return: void
 */
void swap_three(listint_t **list, listint_t *tprev, listint_t *tnext)
{
    if (!tnext->next)
    {
        tprev->prev = tnext;
        tnext->next = tprev;
        tnext->prev = NULL;
        tprev->next = NULL;
        *list = tnext;
        print_list(*list);
    }
    else
    {
        tnext->next->prev = tprev;
        tprev->next = tnext->next;
        tprev->prev = tnext;
        tnext->next = tprev;
        tnext->prev = NULL;
        if (!tnext->prev)
            *list = tnext;
    }
}

/**
 * insertion_sort_list - sort a doubly linked list using
 * insertion sort algo
 * 
 * @list: head of the doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *tnext = NULL, *tprev = NULL, *temp2 = NULL;
    int count = 0, flag = 0;

    if (list == NULL || *list == NULL || !*list || !list || !(*list)->next)
        return;
    tnext = (*list)->next, tprev = *list, temp2 = *list;
    while (tnext)
    {
        if (count == 0)
        {
            if (tprev->n > tnext->n)
            {
                if (!tnext->next)
                {
                    swap_three(list, tprev, tnext);
                    break;
                }
                swap_three(list, tprev, tnext), print_list(*list), flag = 1;
            }
        }
        while (tprev)
        {
            if (tprev->n > tnext->n && flag == 0)
            {
                temp2 = tprev, swap_one(tprev, tnext);
                if (!tnext->prev)
                {
                    *list = tnext;
                    print_list(*list);
                    break;
                }
                print_list(*list);
                tnext = tnext->prev, tprev = tprev->prev, flag = 1;
            }
            else
                break;
            if (tnext->n > tprev->n && flag == 1)
            {
                swap_two(tnext, tprev);
                if (!tprev->prev)
                {
                    *list = tprev, print_list(*list);
                    break;
                }
                print_list(*list);
                tprev = tprev->prev, tnext = tnext->prev, flag = 0;
            }
            else
                break;
        }
        if (temp2->next)
        {
            temp2 = temp2->next, tnext = temp2, tprev = temp2->prev, count = count + 1;
            flag = 0;
        }
        else
            break;
    }
}