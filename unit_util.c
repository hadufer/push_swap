/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:20:38 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/06 16:51:33 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	delete_unit(void *unit)
{
	if (unit)
		free(unit);
	unit = NULL;
}

t_unit	*new_unit(int number, int sorted_index)
{
	t_unit	*out;

	out = malloc(sizeof(out));
	if (!out)
		return (NULL);
	out->number = number;
	out->sorted_index = sorted_index;
	return (out);
}

t_unit	*get_unit_s_index(t_list *list, int number)
{
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (((t_unit *)(tmp->content))->sorted_index == number)
			return ((t_unit *)(tmp->content));
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}

t_unit	*get_unit_number(t_list *list, int number)
{
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (((t_unit *)(tmp->content))->number == number)
			return ((t_unit *)(tmp->content));
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}

t_unit	*get_min_unit(t_list *a)
{
	t_list	*tmp;
	t_unit	*ret;

	tmp = a;
	ret = NULL;
	while (tmp)
	{
		if (!ret)
			ret = ((t_unit *)((tmp)->content));
		if (ret->number >= ((t_unit *)((tmp)->content))->number)
			ret = ((t_unit *)((tmp)->content));
		tmp = tmp->next;
	}
	return (ret);
}
