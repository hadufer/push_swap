/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:37:35 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/05 16:55:03 by hadufer          ###   ########.fr       */
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
