/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:05:52 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/01 13:57:46 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	case_213(t_list **a)
{
	swap(a);
}

void	case_321(t_list **a)
{
	swap(a);
	rrotate(a);
}

void	case_312(t_list **a)
{
	rotate(a);
}

void	case_132(t_list **a)
{
	swap(a);
	rotate(a);
}

void	case_231(t_list **a)
{
	rrotate(a);
}
