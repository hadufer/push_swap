/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:00:22 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/12 20:21:31 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

