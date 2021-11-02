/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:10:19 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/02 14:25:58 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

//Swap the 2 first num of the stack
//Crash if a < 2
void	swap(t_list **a)
{
	void	*tmp;

	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	operation++;
}

//Push a in b (change params to switch between a and b)
//Crash if a doesnt exist
void	push(t_list **a, t_list **b)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_lstnew(new_unit(((t_unit *)((*a)->content))->number, ((t_unit *)((*a)->content))->sorted_index));
	new = (void *)new;
	ft_lstadd_front(b, new);
	tmp = (*a)->next;
	ft_lstdelone(*a, delete_unit);
	*a = tmp;
	operation++;
}

//Rotate the stack
//Crash if a < 2 unit
void	rotate(t_list **a)
{
	t_list	*tmp;
	t_list	*first;

	first = *a;
	tmp = (*a)->next;
	*a = (*a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	operation++;
}

//Reverse rotate the stack
//Crash if a < 2 unit
void	rrotate(t_list **a)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*before_last;

	first = *a;
	tmp = (*a)->next;
	before_last = NULL;
	while (tmp->next)
	{
		if (!tmp->next->next)
			before_last = tmp;
		tmp = tmp->next;
	}
	(*a) = tmp;
	(*a)->next = first;
	if (before_last)
		before_last->next = NULL;
	else
		first->next = NULL;
	operation++;
}
