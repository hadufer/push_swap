/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:57:25 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/06 16:46:24 by hadufer          ###   ########.fr       */
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
