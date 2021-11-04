/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:00:22 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/04 11:58:50 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	list_get_index(t_list *list, int number)
{
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (((t_unit *)(tmp->content))->number == number)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int	list_get_size(t_list *list)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
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

// Return random unit int t_list *a with s_index < quarter_limt
// Return min unit if quarter_limit > list_get_size(a)
t_unit	*get_unit_quarter(t_list *a, int quarter_limit)
{
	t_list	*tmp;

	tmp = a;
	if (quarter_limit >= list_get_size(a) && quarter_limit <= 10)
		return (get_min_unit(a));
	while (tmp)
	{
		if (((t_unit *)((tmp)->content))->sorted_index <= quarter_limit)
			return ((t_unit *)((tmp)->content));
		tmp = tmp->next;
	}
	return (NULL);
}

