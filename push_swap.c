/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:37:35 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/06 15:09:48 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*operation_list;
	long		best_calc;
	long		i_best_calc;
	int			i;

	i = 2;
	best_calc = LONG_MAX;
	if ((ac < 2) || parse_entry(ac, av) == -1)
		return (-1);
	// MiniMax
	while (i <= 12)
	{
		stack_a = init_stack(ac, av);
		stack_b = NULL;
		list_quick_sort(stack_a, 0, list_get_size(stack_a));
		logic(&stack_a, &stack_b, &operation_list, i);
		if (list_get_size(operation_list) < best_calc)
		{
			best_calc = list_get_size(operation_list);
			i_best_calc = i;
		}
		ft_lstclear(&operation_list, free);
		ft_lstclear(&stack_a, delete_unit);
		ft_lstclear(&stack_b, delete_unit);
		i++;
	}
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	list_quick_sort(stack_a, 0, list_get_size(stack_a));
	logic(&stack_a, &stack_b, &operation_list, i_best_calc);
	// print_debug(&stack_a, &stack_b);
	print_operation(&operation_list);
	clear_exit(&stack_a, &stack_b, &operation_list);
}
