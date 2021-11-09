/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:49:24 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/06 17:02:01 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

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
