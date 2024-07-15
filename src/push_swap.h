/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:42:17 by aschmidt          #+#    #+#             */
/*   Updated: 2024/07/15 16:28:35 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/src/libft.h"
# include <limits.h>

// Stack
typedef struct s_list
{
	int				value;
	struct s_list	*next;
}				t_list;

// Parsing
int		*parse_input(int argc, char *argv[]);
int		count_nums(char *s, char c);
void	free_str_arr(char **str_arr);
int		*free_invalid(int *int_arr);
int		has_duplicates(char *arr[]);
int		is_int(char *str);

//Linked list
t_list	*add_new(int value);
void	append_node(t_list **head, int value);
void	print_list(t_list *head);
void	free_list(t_list *head);
int		is_sorted(t_list *head);

//sort
void	sort_two(t_list **head);
void	sort_three(t_list **head);

//swap
void	swap(t_list **head);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

//rotate
void	rotate(t_list **head);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

//rev_rotate
void	rev_rotate(t_list **head);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
#endif
