/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 00:34:17 by ajabado           #+#    #+#             */
/*   Updated: 2024/07/01 00:34:17 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_atoi_strict(const char *str)
{
	int				sign;
	long long int	res;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		res = res * 10 + (*str - 48);
		str++;
	}
	if ((sign * res) > 2147483647 || (sign * res) < -2147483648)
		ft_error();
	return (sign * res);
}

static void	ft_clear_argv(char **argv)
{
	char	*arg;

	if (!argv)
		return ;
	while (*argv)
	{
		arg = *argv;
		argv++;
		free(arg);
	}
	*argv = NULL;
}

static int	ft_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isspace(argv[i][j]))
				while (ft_isspace(argv[i][j]))
					j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static t_stack	*ft_parse_one_arg(char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	argv = ft_split(argv[1], 32);
	if (!ft_check_argv(argv))
	{
		ft_clear_argv(argv);
		free(argv);
		ft_error();
	}
	while (argv[i])
	{
		j = ft_atoi_strict(argv[i]);
		ft_stack_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_clear_argv(argv);
	free(argv);
	return (a);
}

t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_parse_one_arg(argv);
	else
	{
		if (!ft_check_argv(argv + 1))
			ft_error();
		while (i < argc)
		{
			j = ft_atoi_strict(argv[i]);
			ft_stack_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}
