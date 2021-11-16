/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:49:24 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/16 08:57:15 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

int	parse_entry(int *ac, char **av, char ***ret, long *j)
{
	int		i;
	int		start;

	i = 1;
	start = 1;
	*ret = av;
	if (*ac == 2 && *av[1])
	{
		start = 0;
		i = 0;
		*ret = ft_split_more(av[1], " \t\n\v\f\r", ac);
	}
	*j = start;
	while (i < *ac)
	{
		if (!is_valid_int((*ret)[i]) || !is_single(*ac, (*ret), i, start))
		{
			ft_printf("Error\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
