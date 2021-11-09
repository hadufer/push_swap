/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:38:43 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/09 17:49:31 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*op_list;
	char	**ret;
	long	j;

	ret = NULL;
	if ((ac < 2) || parse_entry(&ac, av, &ret, &j) == -1)
	{
		free_ret(ret);
		return (-1);
	}
	stack_a = init_stack(ac, ret, j);
	stack_b = NULL;
	list_quick_sort(stack_a, 0, list_get_size(stack_a));
	if (checker_make_op_list(&stack_a, &stack_b, &op_list) == -1)
		clear_exit(&stack_a, &stack_b, &op_list);
	if (j == 0)
		free_ret(ret);
	checker_logic(&stack_a, &stack_b, &op_list);
}
