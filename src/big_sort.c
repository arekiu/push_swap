/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:02:10 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/25 10:02:13 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more(t_list **stack_a, int size)
{
	t_list		*stack_b;

	if (is_sorted(*stack_a))
		return ;
	stack_b = NULL;
	give_index(stack_a);
	radix(stack_a, &stack_b, size);
}

int	get_bits(t_list **stack_a)
{
	t_list		*head;
	int			temp_max;
	int			bits;

	head = *stack_a;
	temp_max = head->index;
	bits = 0;
	while (head)
	{
		if (head->index > temp_max)
			temp_max = head->index;
		head = head->next;
	}
	while ((temp_max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*head;
	int		i;
	int		j;
	int		bits;

	i = 0;
	head = *stack_a;
	bits = get_bits(stack_a);
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			head = *stack_a;
			if ((head->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (list_size(*stack_b) != 0)
			pa(stack_b, stack_a);
		i++;
	}
}
