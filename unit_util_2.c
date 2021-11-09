/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:50:39 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/06 17:25:57 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

// Return random unit int t_list *a with s_index < quarter_limt
// Return min unit if quarter_limit > list_get_size(a)
t_unit	*get_unit_quarter(t_list *a, int quarter_limit)
{
	t_list	*tmp;

	tmp = a;
	if ((quarter_limit >= list_get_size(a)) && (quarter_limit <= 10))
		return (get_min_unit(a));
	while (tmp)
	{
		if (((t_unit *)((tmp)->content))->sorted_index <= quarter_limit)
			return ((t_unit *)((tmp)->content));
		tmp = tmp->next;
	}
	return (NULL);
}

t_unit	*get_max_unit(t_list *a)
{
	t_list	*tmp;
	t_unit	*ret;

	tmp = a;
	ret = NULL;
	while (tmp)
	{
		if (!ret)
			ret = ((t_unit *)((tmp)->content));
		if (ret->number <= ((t_unit *)((tmp)->content))->number)
			ret = ((t_unit *)((tmp)->content));
		tmp = tmp->next;
	}
	return (ret);
}
