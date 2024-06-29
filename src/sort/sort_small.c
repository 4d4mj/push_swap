/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:51:10 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/29 21:51:10 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	min_position(t_list **stack)
{
	t_list	*tmp;
	int		i;
	int		min;
	int		ret;

	tmp = (*stack);
	min = *(int *)((*stack)->content);
	i = 1;
	ret = 1;
	while (tmp)
	{
		if (*(int *)(tmp->content) < min)
		{
			min = *(int *)(tmp->content);
			ret = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

void	sort_two(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	if (*(int *)(((*stack)->next)->content) < *(int *)(*stack)->content)
		sa(stack);
}

void	sort_three(t_list **stack)
{
	int	top;
	int	middle;
	int	bottom;

	if (!stack || !(*stack))
		return ;
	top = *(int *)((*stack)->content);
	middle = *(int *)(((*stack)->next)->content);
	bottom = *(int *)((((*stack)->next)->next)->content);
	if (top > middle && middle < bottom && top < bottom)
		sa(stack);
	else if (top > middle && middle > bottom)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack);
}

void	sort_four(t_stacks **stacks)
{
	int	posmin;

	if (is_sorted(&((*stacks)->stack_a)))
		return ;
	posmin = min_position(&((*stacks)->stack_a));
	if (posmin >= ft_lstsize((*stacks)->stack_a))
	{
		posmin = ft_lstsize((*stacks)->stack_a) - posmin + 1;
		while (posmin--)
			rra(&((*stacks)->stack_a));
	}
	pb(&(*stacks)->stack_a, &(*stacks)->stack_b);
	sort_three(&((*stacks)->stack_a));
	pa(&((*stacks)->stack_a), &((*stacks)->stack_b));
}

void	sort_five(t_stacks **stacks)
{
	int	posmin;

	if (is_sorted(&((*stacks)->stack_a)))
		return ;
	posmin = min_position(&((*stacks)->stack_a));
	if (posmin >= ft_lstsize((*stacks)->stack_a) / 2)
	{
		posmin = ft_lstsize((*stacks)->stack_a) - posmin + 1;
		while (posmin--)
			rra(&((*stacks)->stack_a));
	}
	if (is_sorted(&((*stacks)->stack_a)))
		return ;
	pb(&((*stacks)->stack_a), &((*stacks)->stack_b));
	posmin = min_position(&((*stacks)->stack_a));
	if (posmin >= ft_lstsize((*stacks)->stack_a) / 2)
	{
		posmin = ft_lstsize((*stacks)->stack_a) - posmin + 1;
		while (posmin--)
			rra(&((*stacks)->stack_a));
	}
	pb(&((*stacks)->stack_a), &((*stacks)->stack_b));
	sort_three(&((*stacks)->stack_a));
	pa(&((*stacks)->stack_a), &((*stacks)->stack_b));
	pa(&((*stacks)->stack_a), &((*stacks)->stack_b));
}
