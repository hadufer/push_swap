/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:40:22 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/04 16:53:11 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	compute_quarter_size(t_list *a)
{
	int	list_size;

	list_size = list_get_size(a);
	if (list_size < 90)
		return (1);
	else if (list_size >= 90 && list_size <= 110)
		return (4);
	else
		return (8);
}

int	logic(t_list **a, t_list **b, t_list **op_list)
{
	long	acc;
	long	quarter_size;

	quarter_size = compute_quarter_size(*a);
	acc = list_get_size(*a) / quarter_size;
	while	(!is_list_sorted(*a))
	{
		if (list_get_size(*a) == 3)
		{
			handler_case_3(a, op_list, 'a');
			break ;
		}
		else if (get_unit_quarter(*a, acc) == NULL)
				acc += list_get_size(*a) / quarter_size + 1;
		else if (list_get_index(*a, get_unit_quarter(*a, acc)->number) > 0)
			median_rotate(a, get_unit_quarter(*a, acc)->number, op_list, 'a');
		else
				push(a, b, op_list, ft_strdup("pb"));
	}
	// problem du ko 96 -97 patch ici
	if (list_get_size(*a) > 3 && !is_top_3_successor(a))
	{
		while (list_get_index(*a, get_max_unit(*b)->number) > 0)
			median_rotate(a, get_max_unit(*a)->number, op_list, 'a');
		push(a, b, op_list, ft_strdup("pb"));
	}
	// SORT LE DERNIER QUARTER SANS PUSH
	while (list_get_size(*b))
	{
		while (list_get_index(*b, get_max_unit(*b)->number) > 0)
			median_rotate(b, get_max_unit(*b)->number, op_list, 'b');
		push(b, a, op_list, ft_strdup("pa"));
		// print_debug(a, b);
	}
	// print_debug(a, b);
	print_operation(op_list);
	return (0);
}
