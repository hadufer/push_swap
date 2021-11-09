/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:37:35 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/09 17:29:46 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	minimax_loop(int ac, char **av, int j)
{
	long	i[3];
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*operation_list;

	i[2] = 2;
	i[0] = LONG_MAX;
	while (i[2] <= 12)
	{
		stack_a = init_stack(ac, av, j);
		stack_b = NULL;
		operation_list = NULL;
		list_quick_sort(stack_a, 0, list_get_size(stack_a));
		logic(&stack_a, &stack_b, &operation_list, i[2]);
		if (list_get_size(operation_list) < i[0])
		{
			i[0] = list_get_size(operation_list);
			i[1] = i[2];
		}
		ft_lstclear(&operation_list, free);
		ft_lstclear(&stack_a, delete_unit);
		ft_lstclear(&stack_b, delete_unit);
		(i[2])++;
	}
	return (i[1]);
}

int	main(int ac, char **av)
{
	t_list	*stack[2];
	t_list	*operation_list;
	long	i_best_calc;
	char	**ret;
	long	j;

	ret = NULL;
	j = -1;
	if ((ac < 2) || parse_entry(&ac, av, &ret, &j) == -1)
	{
		if (j == 0)
			free_ret(ret);
		return (-1);
	}
	i_best_calc = minimax_loop(ac, ret, j);
	stack[0] = init_stack(ac, ret, j);
	stack[1] = NULL;
	list_quick_sort(stack[0], 0, list_get_size(stack[0]));
	logic(&stack[0], &stack[1], &operation_list, i_best_calc);
	print_operation(&operation_list);
	if (j == 0)
		free_ret(ret);
	clear_exit(&stack[0], &stack[1], &operation_list);
}
