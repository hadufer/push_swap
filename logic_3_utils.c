/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_3_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:37:46 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/02 12:03:05 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	handler_case_3(t_list **a, t_list **b)
{
	int	first_s_index;
	int	second_s_index;
	int	third_s_index;

	(void)b;
	first_s_index = ((t_unit *)(*a)->content)->sorted_index;
	second_s_index = ((t_unit *)((*a)->next->content))->sorted_index;
	third_s_index = ((t_unit *)((*a)->next->next->content))->sorted_index;
	if ((third_s_index > first_s_index) && (first_s_index > second_s_index))
		case_213(a);
	else if ((first_s_index > second_s_index) && (second_s_index > third_s_index))
		case_321(a);
	else if ((first_s_index > third_s_index) && (third_s_index > second_s_index))
		case_312(a);
	else if ((second_s_index > third_s_index) && (third_s_index > first_s_index))
		case_132(a);
	else if ((second_s_index > first_s_index) && (first_s_index > third_s_index))
		case_231(a);
	else
		return (0);
	return (-1);
}
