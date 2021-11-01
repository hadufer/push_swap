/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:40:51 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/01 18:31:21 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

//	Do the median of the stack t_list and apply
//	rotate or rrotate based on wich one is the more
//	efficient.
void	median_rotate(t_list **a, int num)
{
	int	index;
	int	median;

	index = list_get_index(*a, num);
	median = (list_get_size(*a) / 2);
	if (median > index)
		rotate(a);
	else
		rrotate(a);
}

