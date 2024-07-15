/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:04:30 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/15 16:37:08 by aschmidt         ###   ########.fr       */
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
	if ((*head)->value > (*head)->next->value)
	{
		if ((*head)->next->value > (*head)->next->next->value)
		{
			sa(head);
			rra(head);
		}
		else
			ra(head);
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
