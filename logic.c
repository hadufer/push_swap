/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:40:22 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/05 18:23:46 by hadufer          ###   ########.fr       */
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

int	logic(t_list **a, t_list **b, t_list **op_list, int key_nbr)
{
	long	acc;
	long	quarter_size;


	quarter_size = compute_quarter_size(*a);
	acc = list_get_size(*a) / quarter_size;
	if (key_nbr)
		quarter_size = key_nbr;
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
	if ((list_get_size(*a) > 3) && !is_top_3_successor(a))
	{
		while (list_get_index(*a, get_min_unit(*a)->number) > 0)
			median_rotate(a, get_min_unit(*a)->number, op_list, 'a');
		push(a, b, op_list, ft_strdup("pb"));
	}
	while (list_get_size(*b))
	{
		if ((list_get_index(*b, get_max_unit(*b)->number) == 0) && ((list_get_size(*b) >= 3) && is_top_3_successor(b)))
			handler_case_3(b, op_list, 'b');
		while (list_get_index(*b, get_max_unit(*b)->number) > 0)
			median_rotate(b, get_max_unit(*b)->number, op_list, 'b');
		if (list_get_index(*b, get_max_unit(*b)->number) == 0)
			push(b, a, op_list, ft_strdup("pa"));
	}
	return (0);
}
