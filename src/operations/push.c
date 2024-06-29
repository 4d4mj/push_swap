/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:49:12 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/29 21:49:12 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_list **src, t_list **dst)
{
	t_list	*node;

	if (!src || !dst || !(*src))
		return ;
	node = *src;
	if ((*src)->next)
		node->next->prev = NULL;
	else
		(*src)->prev = NULL;
	*src = (*src)->next;
	node->next = NULL;
	ft_lstadd_front(dst, node);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
