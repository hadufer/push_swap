/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:35:28 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/12 18:06:20 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_unit	*get_unit_s_index(t_list *list, int number)
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

static t_unit	*get_unit_number(t_list *list, int number)
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

static void	swap_s_index(t_unit *a, t_unit *b)
{
	int	tmp;

	tmp = a->sorted_index;
	a->sorted_index = b->sorted_index;
	b->sorted_index = tmp;
}

static int	list_partition(t_list *list, int low, int high)
{
	int	pivot;
	int	leftwall;
	int	i;

	i = low;
	pivot = get_unit_s_index(list, low)->number;
	leftwall = low;
	while (i < high)
	{
		if (get_unit_s_index(list, i)->number < pivot)
		{
			swap_s_index(get_unit_s_index(list, i), get_unit_s_index(list, leftwall));
			leftwall++;
		}
		i++;
	}
	swap_s_index(get_unit_number(list, pivot), get_unit_s_index(list, leftwall));
	return (leftwall);
}

void	list_quick_sort(t_list *list, int low, int high)
{
	int	pivot_location;

	if (low < high)
	{
		pivot_location = list_partition(list, low, high);
		list_quick_sort(list, low, pivot_location);
		list_quick_sort(list, pivot_location + 1, high);
	}
}
