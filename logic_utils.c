/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:40:51 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/03 14:22:29 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

//	Do the median of the stack t_list and apply
//	rotate or rrotate based on wich one is the more
//	efficient.
void	median_rotate(t_list **a, int num, t_list **op_list, int stack)
{
	int		index;
	int		median;
	char	tmp[2];

	tmp[0] = stack;
	tmp[1] = 0;
	index = list_get_index(*a, num);
	median = (list_get_size(*a) / 2);
	if (median > index)
		rotate(a, op_list, ft_strjoin("r", tmp));
	else
		rrotate(a, op_list, ft_strjoin("rr", tmp));
}

//	Return 1 if t_list is sorted in order else 0;
int	is_list_sorted(t_list *a)
{
	t_list	*tmp;
	int		last_num;

	tmp = a;
	last_num = ((t_unit *)(tmp->content))->sorted_index;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp && (last_num > ((t_unit *)(tmp->content))->sorted_index))
			return (0);
		if (tmp)
			last_num = ((t_unit *)(tmp->content))->sorted_index;
	}
	return (1);
}
