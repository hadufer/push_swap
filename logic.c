/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:40:22 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/01 18:43:00 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	logic(t_list **a, t_list **b)
{
	while (list_get_size(*a))
	{
		if (list_get_size(*a) == 3)
		{
			handler_case_3(a, b);
			return (0);
		}
		else
		{
			while (list_get_size(*a) > 3)
			{
				if (list_get_index(*a, get_min_unit(*a)->number) > 0)
					median_rotate(a, get_min_unit(*a)->number);
				else
					push(a, b);
			}
			while (list_get_size(*b))
				push(b, a);
		}
	}
	while (list_get_size(*b))
		push(b, a);
	return (0);
}
