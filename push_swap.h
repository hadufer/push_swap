/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:09:23 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/13 18:57:06 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_unit
{
	int				number;
	int				sorted_index;
}					t_unit;
int				is_single(int ac, char **av, int str_test_index);
int				str_is_digit(char *str);
int				is_valid_int(char *str);
int				parse_entry(int ac, char **av);
void			clear_exit(t_list *stack_a, t_list *stack_b);
int				list_get_index(t_list *list, int number);
int				list_get_size(t_list *list);
void			list_quick_sort(t_list *list, int low, int high);
t_unit			*new_unit(int number, int sorted_index);
void			delete_unit(void *unit);
void			push(t_list **a, t_list **b);
void			swap(t_list **a);
void			rotate(t_list **a);
void			rrotate(t_list **a);
#endif
