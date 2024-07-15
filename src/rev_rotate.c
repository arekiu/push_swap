#include "push_swap.h"

void	rev_rotate(t_list **head)
{
	t_list	*prev;
	t_list	*last;

	if (!*head || (*head)->next == NULL)
		return ;
	prev = NULL;
	last = *head;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = *head;
    *head = last;
}

void	rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
