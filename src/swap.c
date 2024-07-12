#include "push_swap.h"

void    swap(t_list **head)
{
    t_list *first;
    t_list *second;

    if (!*head || (*head)->next == NULL)
		return ;
    first = *head;
    second = (*head)->next;
    first->next = second->next;
    second->next = first;
    *head = second;
}

void sa(t_list **stack_a)
{
    swap(stack_a);
    ft_printf("sa\n");
}

