/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:34:51 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/15 16:30:44 by aschmidt         ###   ########.fr       */
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
	print_list(stack_a);
	if (is_sorted(stack_a))
		return;
	if (size == 2)
		sort_two(&stack_a);
	if (size == 3)
		sort_three(&stack_a);
	print_list(stack_a);
	free_list(stack_a);
}

int	main(int argc, char *argv[])
{
	int	*int_arr;
	int	size;

	if (argc == 1)
	{
		ft_printf("You must provide a list of numbers\n");
		return (0);
	}
	else if (argc == 2)
	{
		if (count_nums(argv[1], ' ') == 1)
			return (0);
		else
			size = count_nums(argv[1], ' ');
	}
	else
		size = argc - 1;
	int_arr = parse_input(argc, argv);
	if (!int_arr)
		return (0);
	sort_list(int_arr, size);
	return (0);
}
