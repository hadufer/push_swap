/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:40:22 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/16 08:47:40 by hadufer          ###   ########.fr       */
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

void	logic_2(t_list **a, t_list **b, t_list **op_list)
{
	if ((list_get_size(*a) > 3) && !is_top_3_successor(a))
	{
		while (list_get_index(*a, get_min_unit(*a)->number) > 0)
			median_rotate(a, get_min_unit(*a)->number, op_list, 'a');
		push(a, b, op_list, ft_strdup("pb"));
	}
	while (list_get_size(*b))
	{
		while (list_get_index(*b, get_max_unit(*b)->number) > 0)
			median_rotate(b, get_max_unit(*b)->number, op_list, 'b');
		if (list_get_index(*b, get_max_unit(*b)->number) == 0)
			push(b, a, op_list, ft_strdup("pa"));
	}
}

void	logic_main(t_list **a, t_list **b, t_list **op_list, long *tab)
{
	while (!is_list_sorted(*a))
	{
		if (list_get_size(*a) == 3)
		{
			handler_case_3(a, op_list, 'a');
			break ;
		}
		else if (get_unit_quarter(*a, tab[0]) == NULL)
			tab[0] += list_get_size(*a) / tab[1] + 1;
		else if (list_get_index(*a, get_unit_quarter(*a, tab[0])->number) > 0)
			median_rotate(a, get_unit_quarter(*a,
					tab[0])->number, op_list, 'a');
		else
			push(a, b, op_list, ft_strdup("pb"));
	}
}

int	logic(t_list **a, t_list **b, t_list **op_list, int key_nbr)
{
	long	tab[2];

	tab[1] = key_nbr;
	tab[0] = list_get_size(*a) / tab[1];
	logic_main(a, b, op_list, tab);
	logic_2(a, b, op_list);
	logic_main(a, b, op_list, tab);
	logic_2(a, b, op_list);
	logic_main(a, b, op_list, tab);
	return (0);
}
