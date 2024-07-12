#include "push_swap.h"

void sort_two(t_list **head)
{
    if ((*head)->value > (*head)->next->value)
        sa(head);
}