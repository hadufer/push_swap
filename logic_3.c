/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:05:52 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/03 11:37:27 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	case_213(t_list **a, t_list **op, int stack)
{
	char	tmp[2];

	tmp[1] = 0;
	tmp[0] = stack;
	swap(a, op, ft_strjoin("s", tmp));
}

void	case_321(t_list **a, t_list **op, int stack)
{
	char	tmp[2];

	tmp[1] = 0;
	tmp[0] = stack;
	swap(a, op, ft_strjoin("s", tmp));
	rrotate(a, op, ft_strjoin("rr", tmp));
}

void	case_312(t_list **a, t_list **op, int stack)
{
	char	tmp[2];

	tmp[1] = 0;
	tmp[0] = stack;
	rotate(a, op, ft_strjoin("r", tmp));
}

void	case_132(t_list **a, t_list **op, int stack)
{
	char	tmp[2];

	tmp[1] = 0;
	tmp[0] = stack;
	swap(a, op, ft_strjoin("s", tmp));
	rotate(a, op, ft_strjoin("r", tmp));
}

void	case_231(t_list **a, t_list **op, int stack)
{
	char	tmp[2];

	tmp[1] = 0;
	tmp[0] = stack;
	rrotate(a, op, ft_strjoin("rr", tmp));
}
