/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:04:30 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/17 15:54:29 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **head)
{
	if ((*head)->value > (*head)->next->value)
		sa(head);
}

void	sort_three(t_list **head)
{
	if (is_sorted(*head))
		return ;
	if ((*head)->value > (*head)->next->value)
	{
		if ((*head)->next->value > (*head)->next->next->value)
		{
			sa(head);
			rra(head);
		}
		else if ((*head)->value > (*head)->next->next->value)
			ra(head);
		else
			sa(head);
	}
	else
	{
		if ((*head)->next->next->value < (*head)->value)
			rra(head);
		else
		{
			sa(head);
			ra(head);
		}
	}
}

static	void leave_three(t_list **stack_a, t_list **stack_b, int index, int size)
{
	if (index == 0)
		pb(stack_a, stack_b);
	else if (index == 1)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 2)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 3)
	{
		if (size == 5)
			rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	sort_five(t_list **stack_a)
{
	t_list *stack_b;
	int		index;
	int		size;

	size = list_size(*stack_a);
	stack_b = NULL;
	index = find_index_smallest(*stack_a);
	leave_three(stack_a, &stack_b, index, size);
	size = list_size(*stack_a);
	index = find_index_smallest(*stack_a);
	leave_three(stack_a, &stack_b, index, size);
	sort_three(stack_a);
	pa(&stack_b, stack_a);
	pa(&stack_b, stack_a);
}
