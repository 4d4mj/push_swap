/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:05:42 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/29 22:05:42 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	free_stacks(t_stacks *stacks, int argc, char **args)
{
	char	**tmp;

	if (argc == 2)
	{
		tmp = args;
		while (*tmp)
			free(*tmp++);
		free(args);
	}
	if (stacks->stack_a)
		ft_lstclear(&(stacks->stack_a), &free);
	free(stacks);
}

int	main(int argc, char **argv)
{
	char		**args;
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], WHITE_SPACE);
	else
		args = argv;
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!args || !stacks)
		return (-1);
	stacks->stack_a = ft_init(args, argc);
	if (!(stacks->stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stacks(stacks, argc, args);
		return (-1);
	}
	stacks->stack_b = NULL;
	stacks->a_size = ft_lstsize(stacks->stack_a);
	stacks->stack_b = 0;
	sort(&stacks);
	free_stacks(stacks, argc, args);
	return (0);
}
