/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:05:15 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/29 22:05:15 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_is_valid(t_list *list, int nbr)
{
	t_list	*tmp;

	tmp = list;
	while (tmp && tmp->content)
	{
		if (*(int *)(tmp->content) == nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	*handle_nb(char *arg, t_list *ret, int **ptr)
{
	int	nb;
	char *tmp;

	tmp = arg;
	while (*tmp)
	{
		if ((*tmp < '0' || *tmp > '9') && (*tmp != '-' && *tmp != '+'))
			return (NULL);
		tmp++;
	}
	nb = ft_atoi(arg);
	if (ft_is_valid(ret, nb))
		*ptr = malloc(sizeof(int));
	else
		return (NULL);
	if (!*ptr)
		return (NULL);
	**ptr = nb;
	return (*ptr);
}

t_list	*ft_init(char **args, int count)
{
	t_list	*ret;
	t_list	*tmp;
	int		*ptr;

	if (count != 2)
		args++;
	ret = NULL;
	ptr = NULL;
	while (*args)
	{
		handle_nb(*(args++), ret, &ptr);
		if (!ptr)
		{
			ft_lstclear(&ret, &free);
			return (NULL);
		}
		else
			tmp = ft_lstnew(ptr);
		if (!tmp)
		{
			free(ptr);
			ft_lstclear(&ret, &free);
			return (NULL);
		}
		ft_lstadd_back(&ret, tmp);
	}
	return (ret);
}
