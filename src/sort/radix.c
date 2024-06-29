/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:50:03 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/29 21:50:03 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_bits(int nb)
{
	int	bits;

	bits = 1;
	nb >>= 1;
	while (nb > 0)
	{
		nb >>= 1;
		bits++;
	}
	return (bits);
}

static int	ft_lstintmax(t_list **stack)
{
	t_list	*tmp;
	int		max;

	if (!stack || !(*stack))
		return (0);
	tmp = *stack;
	max = *(int *)(tmp->content);
	while (tmp && tmp->next != NULL)
	{
		if (max < *(int *)(tmp->next->content))
			max = *(int *)(tmp->next->content);
		tmp = tmp->next;
	}
	return (max);
}

void	sort_radix(t_stacks **stacks)
{
	int	bits;
	int	bit;
	int	sizeof_stack;
	int	i;
	int	j;

	i = -1;
	bits = count_bits(ft_lstintmax(&((*stacks)->stack_a)));
	sizeof_stack = (*stacks)->a_size;
	while (++i <= bits)
	{
		j = -1;
		while (++j < sizeof_stack)
		{
			bit = ((*(int *)((*stacks)->stack_a->content)) >> i) & 1;
			if (bit == 0)
				pb(&(*stacks)->stack_a, &(*stacks)->stack_b);
			else
				ra(&(*stacks)->stack_a);
		}
		while ((*stacks)->stack_b != NULL)
			pa(&((*stacks)->stack_a), &((*stacks)->stack_b));
		if (is_sorted(&((*stacks)->stack_a)))
			return ;
	}
}
