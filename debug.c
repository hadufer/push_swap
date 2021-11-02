/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:07:17 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/02 14:25:48 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	print_debug(t_list **a, t_list **b)
{
	// DEBUG
	t_list *tmp = *a;
	t_list *tmp2 = *b;

	ft_printf("STACK A:\n");
	while (tmp)
	{
		ft_printf("index:%d = value:%d\n", ((t_unit *)(tmp->content))->sorted_index, ((t_unit *)(tmp->content))->number);
		tmp = tmp->next;
	}
	ft_printf("STACK B:\n");
	while (tmp2)
	{
		ft_printf("index:%d = value:%d\n", ((t_unit *)(tmp2->content))->sorted_index, ((t_unit *)(tmp2->content))->number);
		tmp2 = tmp2->next;
	}
	ft_printf("OPERATION: %d\n", operation);
}
