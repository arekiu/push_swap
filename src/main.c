/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:34:51 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/25 09:42:02 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*initialize_list(int *arr, int size)
{
	t_list	*head;
	int		i;

	head = NULL;
	i = 0;
	while (i < size)
	{
		append_node(&head, arr[i]);
		i++;
	}
	return (head);
}

void	sort_list(int *arr, int size)
{
	t_list	*stack_a;

	stack_a = initialize_list(arr, size);
	free(arr);
	//print_list(stack_a);
	if (is_sorted(stack_a) || size == 1)
	{
		free_list(stack_a);
		return ;
	}
	if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 4)
		sort_four(&stack_a);
	else if (size == 5)
		sort_five(&stack_a);
	else
		sort_more(&stack_a, size);
	//print_list(stack_a);
	free_list(stack_a);
}

int	main(int argc, char *argv[])
{
	int	*int_arr;
	int	size;

	if (argc == 2)
		size = count_nums(argv[1], ' ');
	else
		size = argc - 1;
	int_arr = parse_input(argc, argv);
	if (!int_arr)
		return (0);
	sort_list(int_arr, size);
	return (0);
}
