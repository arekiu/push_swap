/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:34:51 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/09 16:59:07 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	//int		i;
	//t_list	num_list;
	//int	*num_arr;

	if (argc == 1)
	{
		ft_printf("You must provide a list of numbers\n");
		return (0);
	}
	parse_input(argc, argv);
	
	return (0);
}
