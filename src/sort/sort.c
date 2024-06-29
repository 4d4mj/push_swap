/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:49:31 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/29 21:49:31 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_list **list)
{
	t_list	*tmp;

	if (!list || !(*list))
		return (0);
	tmp = *list;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort(t_stacks **stacks)
{
	if (!stacks || !(*stacks) || (*stacks)->a_size == 1)
		return ;
	if ((*stacks)->a_size == 2)
		sort_two(&((*stacks)->stack_a));
	else if ((*stacks)->a_size == 3)
		sort_three(&((*stacks)->stack_a));
	else if ((*stacks)->a_size == 4)
		sort_four(stacks);
	else if ((*stacks)->a_size == 5)
		sort_five(stacks);
	else
	{
		if (is_sorted(&((*stacks)->stack_a)))
			return ;
		sort_radix(stacks);
	}
}
