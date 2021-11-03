/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:07:17 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/03 16:22:38 by hadufer          ###   ########.fr       */
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
	ft_printf("OPERATION: %d\n", operation_g);
}

void	print_operation(t_list **op_list)
{
	t_list	*tmp;

	tmp = *op_list;
	while (tmp)
	{
		ft_putendl_fd((char *)(tmp->content), 1);
		tmp = tmp->next;
	}
}
