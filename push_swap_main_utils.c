/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:21:18 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/06 09:21:19 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

t_unit	*init_new_unit(char *str_digit, unsigned int sorted_index)
{
	t_unit	*out;
	char	*trimed_str_digit;

	out = malloc(sizeof(out));
	if (out == NULL)
		return (NULL);
	trimed_str_digit = ft_strtrim(str_digit, " \t\n\v\f\r");
	out->number = ft_atoi(trimed_str_digit);
	free(trimed_str_digit);
	out->sorted_index = sorted_index;
	return (out);
}

t_list	*init_stack(int ac, char **av)
{
	t_list			*out;
	t_unit			*tmp_u;
	unsigned int	i;

	i = 1;
	out = ft_lstnew(init_new_unit(av[i], i - 1));
	if (!out)
		return (NULL);
	i++;
	while (i < (unsigned int)ac)
	{
		tmp_u = init_new_unit(av[i], i - 1);
		if (tmp_u == NULL)
			return (NULL);
		ft_lstadd_back(&out, ft_lstnew(tmp_u));
		i++;
	}
	return (out);
}

void	clear_exit(t_list **stack_a, t_list **stack_b, t_list **op_list)
{
	(void)op_list;
	if (*stack_a)
		ft_lstclear(stack_a, delete_unit);
	if (*stack_b)
		ft_lstclear(stack_b, delete_unit);
	if (*op_list)
		ft_lstclear(op_list, free);
	exit(0);
}
