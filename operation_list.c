/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:57:25 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/04 17:49:48 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

//	Add a t_list at the back of the chain
void	add_op(t_list **operation, char *op_name)
{
	ft_lstadd_back(operation, ft_lstnew(op_name));
}

//	Delete the t_list * based on his index
void	del_op(t_list **operation, int index)
{
	long	i;
	t_list	*tmp;
	t_list	*tmp_prev;

	i = 0;
	tmp = *operation;
	if (!operation || !*operation)
		return ;
	while (tmp && (i < index))
	{
		i++;
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	if ((i == index) && (tmp_prev && (tmp && tmp->next)))
	{
		ft_lstdelone(tmp, free);
		tmp_prev->next = tmp->next;
	}
	else if ((i == index) && (tmp_prev && (tmp && !tmp->next)))
	{
		ft_lstdelone(tmp, free);
		tmp_prev->next = NULL;
	}
	else if ((i == index) && (!tmp_prev && (tmp && !tmp->next)))
		ft_lstclear(operation, free);
}
