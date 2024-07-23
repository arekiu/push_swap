/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:49:43 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/23 15:53:18 by aschmidt         ###   ########.fr       */
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
t_list	*find_next_smallest(t_list **stack_a)
{
	t_list		*head;
	t_list		*smallest;
	int			found;

	found = 0;
	smallest = NULL;
	head = *stack_a;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!found || head->value < smallest->value))
			{
				smallest = head;
				found = 1;
			}
			head = head->next;
		}
	}
	return (smallest);
}

void	give_index(t_list **stack_a)
{
	t_list	*head;
	int		index;

	index = 0;
	head = find_next_smallest(stack_a);
	while (head)
	{
		head->index = index;
		head = find_next_smallest(stack_a);
		index++;
	}
}
