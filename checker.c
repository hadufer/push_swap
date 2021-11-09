/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 08:56:31 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/09 18:02:20 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "get_next_line.h"
#include <stdlib.h>

int	is_op_arg_valid(char *op_arg)
{
	if (!op_arg)
		return (0);
	if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "sa\n", 3))
		return (1);
	if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "sb\n", 3))
		return (1);
	if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "ss\n", 3))
		return (1);
	if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "pa\n", 3))
		return (1);
	if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "pb\n", 3))
		return (1);
	if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "ra\n", 3))
		return (1);
	if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "rb\n", 3))
		return (1);
	if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "rr\n", 3))
		return (1);
	if (ft_strlen(op_arg) == 4 && !ft_strncmp(op_arg, "rra\n", 4))
		return (1);
	if (ft_strlen(op_arg) == 4 && !ft_strncmp(op_arg, "rrb\n", 4))
		return (1);
	if (ft_strlen(op_arg) == 4 && !ft_strncmp(op_arg, "rrr\n", 4))
		return (1);
	return (0);
}

int	checker_make_op_list(t_list **a, t_list **b, t_list **op_list)
{
	char	*tmp;

	(void)b;
	(void)a;
	tmp = get_next_line(0);
	while (tmp)
	{
		if (is_op_arg_valid(tmp) == 0)
		{
			ft_printf("Error\n");
			free(tmp);
			return (-1);
		}
		tmp[ft_strlen(tmp)] = 0;
		add_op(op_list, tmp);
		tmp = get_next_line(0);
	}
	return (0);
}

int	checker_dispatch_2(t_list **a, t_list **b, char *op_arg, t_list *tmp)
{
	if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "pb\n", 3))
		push(a, b, &tmp, NULL);
	else if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "ra\n", 3))
		rotate(a, &tmp, NULL);
	else if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "rb\n", 3))
		rotate(b, &tmp, NULL);
	else if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "rr\n", 3))
	{
		rotate(a, &tmp, NULL);
		rotate(b, &tmp, NULL);
	}
	else if (ft_strlen(op_arg) == 4 && !ft_strncmp(op_arg, "rra\n", 4))
		rrotate(a, &tmp, NULL);
	else if (ft_strlen(op_arg) == 4 && !ft_strncmp(op_arg, "rrb\n", 4))
		rrotate(b, &tmp, NULL);
	else if (ft_strlen(op_arg) == 4 && !ft_strncmp(op_arg, "rrr\n", 4))
	{
		rrotate(a, &tmp, NULL);
		rrotate(b, &tmp, NULL);
	}
	return (0);
}

int	checker_dispatch(t_list **a, t_list **b, char *op_arg)
{
	t_list	*tmp;

	tmp = NULL;
	if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "sa\n", 3))
		swap(a, &tmp, NULL);
	else if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "sb\n", 3))
		swap(b, &tmp, NULL);
	else if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "ss\n", 3))
	{
		swap(a, &tmp, NULL);
		swap(b, &tmp, NULL);
	}
	else if (ft_strlen(op_arg) == 3 && !ft_strncmp(op_arg, "pa\n", 3))
		push(b, a, &tmp, NULL);
	else if (!checker_dispatch_2(a, b, op_arg, tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (0);
}

void	checker_logic(t_list **a, t_list **b, t_list **op_list)
{
	t_list	*tmp;

	tmp = *op_list;
	while (tmp)
	{
		checker_dispatch(a, b, ((char *)(tmp->content)));
		tmp = tmp->next;
	}
	if (list_get_size(*b) == 0 && is_list_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_exit(a, b, op_list);
}
