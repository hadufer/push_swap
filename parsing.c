/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:58:14 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/05 09:10:02 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <limits.h>
#include <stdlib.h>

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static long	ft_cmp_int(char *a, char *b)
{
	long	ret;

	a = ft_strtrim(a, " \t\n\v\f\r");
	b = ft_strtrim(b, " \t\n\v\f\r");
	ret = ft_atoi(a) - ft_atoi(b);
	free(a);
	free(b);
	return (ret);
}

int	is_single(int ac, char **av, int to_test)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (i != to_test && !ft_cmp_int(av[i], av[to_test]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_int(char *str)
{
	int		i;
	long	out;
	int		neg;

	i = 0;
	out = 0;
	neg = 1;
	str = ft_strtrim(str, " \t\n\v\f\r");
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = (str[i] - 48) + (10 * out);
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		free(str);
		return (0);
	}
	out *= neg;
	if (out > INT_MAX || out < INT_MIN)
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

int	parse_entry(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_int(av[i]) || !is_single(ac, av, i))
		{
			ft_printf("Error\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
