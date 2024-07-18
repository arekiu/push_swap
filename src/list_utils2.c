/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:49:43 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/18 10:49:45 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_smallest(t_list *stack_a)
{
	t_list		*current;
	t_list		*smallest;
	int			index;
	int			smallest_index;

	smallest = stack_a;
	index = 0;
	smallest_index = 0;
	current = stack_a->next;
	while (current != NULL)
	{
		if (current->value < smallest->value)
		{
			smallest = current;
			smallest_index = index + 1;
		}
		current = current->next;
		index++;
	}
	return (smallest_index);
}

int	list_size(t_list *head)
{
	t_list		*current;
	int			i;

	i = 0;
	current = head;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
