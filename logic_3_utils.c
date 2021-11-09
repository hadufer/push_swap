/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_3_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:37:46 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/06 16:45:54 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	handler_case_3(t_list **a, t_list **op_list, int stack)
{
	int	first_s_index;
	int	second_s_index;
	int	third_s_index;

	first_s_index = ((t_unit *)(*a)->content)->sorted_index;
	second_s_index = ((t_unit *)((*a)->next->content))->sorted_index;
	third_s_index = ((t_unit *)((*a)->next->next->content))->sorted_index;
	if ((third_s_index > first_s_index) && (first_s_index > second_s_index))
		case_213(a, op_list, stack);
	else if ((first_s_index > second_s_index)
		&& (second_s_index > third_s_index))
		case_321(a, op_list, stack);
	else if ((first_s_index > third_s_index)
		&& (third_s_index > second_s_index))
		case_312(a, op_list, stack);
	else if ((second_s_index > third_s_index)
		&& (third_s_index > first_s_index))
		case_132(a, op_list, stack);
	else if ((second_s_index > first_s_index)
		&& (first_s_index > third_s_index))
		case_231(a, op_list, stack);
	else
		return (0);
	return (-1);
}

//	Return 1 if a is direct successor of b
//	Return -1 if b is direct successor of a
//	Return 0 if there's no direct successor
int	is_successor(int a, int b)
{
	long	tmpa;
	long	tmpb;

	tmpa = a;
	tmpb = b;
	if (tmpa + 1 == tmpb)
		return (1);
	else if (tmpa - 1 == tmpb)
		return (-1);
	return (0);
}

//	Will check wether or not the top 3
//	unit of stack are "successors" to use handle_case_3
int	is_top_3_successor(t_list **a)
{
	long	first_s_index;
	long	second_s_index;
	long	third_s_index;

	first_s_index = ((t_unit *)(*a)->content)->sorted_index;
	second_s_index = ((t_unit *)((*a)->next->content))->sorted_index;
	third_s_index = ((t_unit *)((*a)->next->next->content))->sorted_index;
	if (is_successor(first_s_index, second_s_index) == 1
		&& is_successor(first_s_index, third_s_index) == -1)
		return (1);
	else if (is_successor(first_s_index, second_s_index) == 1
		&& is_successor(second_s_index, third_s_index) == 1)
		return (1);
	else if (is_successor(first_s_index, third_s_index) == 1
		&& is_successor(third_s_index, second_s_index) == 1)
		return (1);
	else if (is_successor(second_s_index, third_s_index) == 1
		&& is_successor(third_s_index, first_s_index) == 1)
		return (1);
	else if (is_successor(first_s_index, second_s_index) == -1
		&& is_successor(third_s_index, first_s_index) == -1)
		return (1);
	return (0);
}
