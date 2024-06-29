/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:48:39 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/29 21:48:39 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define WHITE_SPACE 32
# define STD_IN 0

# include "../src/libft/includes/libft.h"

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		a_size;
	int		b_size;
}			t_stacks;

t_list		*ft_init(char **args, int count);
void		sa(t_list **stack);
void		sb(t_list **stack);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack);
void		rb(t_list **stack);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack);
void		rrb(t_list **stack);
void		rrr(t_list **stack_a, t_list **stack_b);
void		sort(t_stacks **stacks);
void		sort_two(t_list **stack);
void		sort_three(t_list **stack);
void		sort_four(t_stacks **stacks);
void		sort_five(t_stacks **stacks);
void		sort_radix(t_stacks **stacks);
int			is_sorted(t_list **list);

#endif
