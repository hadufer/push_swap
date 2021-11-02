/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:40:22 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/02 15:33:35 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	compute_quarter_size(t_list *a)
{
	int	list_size;

	list_size = list_get_size(a);
	if (list_size < 100)
		return (1);
	if (list_size == 100)
		return (8);
	return (1); // a changer
}

// int	logic(t_list **a, t_list **b)
// {
// 	long	acc;
// 	long	quarter_size;

// 	acc = 0;
// 	quarter_size = 2;
// 	while	(!is_list_sorted(*a))
// 	{
// 		if (list_get_size(*a) == 3)
// 		{
// 			handler_case_3(a, b);
// 			// print_debug(a, b);
// 			break ;
// 		}
// 		else if (get_min_unit_quarter(*a, (list_get_size(*a) / quarter_size) + acc) == NULL)
// 			acc += list_get_size(*a) / quarter_size;
// 		else if (list_get_index(*a, get_min_unit_quarter(*a, (list_get_size(*a) / quarter_size) + acc)->number) > 0)
// 		{
// 			median_rotate(a, get_min_unit(*a)->number);
// 			// print_debug(a, b);
// 		}
// 		else
// 		{
// 			push(a, b);
// 			// print_debug(a, b);
// 		}
// 	}
// 	while (list_get_size(*b))
// 	{
// 		push(b, a);
// 		// print_debug(a, b);
// 	}
// 	print_debug(a, b);
// 	return (0);
// }

int	logic(t_list **a, t_list **b)
{
	long	acc;
	long	quarter_size;

	quarter_size = 4;
	acc = 0;
	while	(!is_list_sorted(*a))
	{
		if (list_get_size(*a) == 3)
		{
			handler_case_3(a, b);
			break ;
		}
		else if (get_min_unit_quarter(*a, list_get_size(*a) / quarter_size + acc) == NULL)
			acc += list_get_size(*a) / quarter_size;
		else if (list_get_index(*a, get_min_unit_quarter(*a, (list_get_size(*a) / quarter_size) + acc)->number) > 0)
			median_rotate(a, get_min_unit_quarter(*a, list_get_size(*a) / quarter_size + acc)->number);
		else
			push(a, b);
	}
	while (list_get_size(*b))
	{
		while (list_get_index(*b, get_min_unit(*b)->number) > 0)
			median_rotate(b, get_min_unit(*b)->number);
		push(b, a);
	}
	print_debug(a, b);
	return (0);
}
