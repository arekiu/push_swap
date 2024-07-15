/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:34:51 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/15 13:48:53 by aschmidt         ###   ########.fr       */
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
	t_list	*head;

	head = initialize_list(arr, size);
	free(arr);
	print_list(head);
	if (size == 2)
		sort_two(&head);
	print_list(head);
	free_list(head);
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
