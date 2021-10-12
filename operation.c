/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:10:19 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/12 20:32:44 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Swap the 2 first num of the stack
void	swap(t_list *list)
{
	void	*tmp;

	// if (!list->next)
	// 	return ;
	tmp = list->content;
	list->content = list->next->content;
	list->next->content = tmp;
}

// Push a in b (rotate params to switch between a and b)
void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	if (!(*a)->next)
		ft_lstdelone(*a, delete_unit);
	else
		*a = (*a)->next;
	if (!(*b))
		*b = ft_lstnew(new_unit(((t_unit *)tmp->content)->number,
			((t_unit *)tmp->content)->sorted_index));
	else
		ft_lstadd_front(b, tmp);
	ft_lstdelone(tmp, delete_unit);
}
