/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:09:23 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/06 16:46:33 by hadufer          ###   ########.fr       */
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
void			clear_exit(t_list **stack_a,
					t_list **stack_b, t_list **op_list);
int				list_get_index(t_list *list, int number);
int				list_get_size(t_list *list);
void			list_quick_sort(t_list *list, int low, int high);
t_unit			*new_unit(int number, int sorted_index);
void			delete_unit(void *unit);
t_unit			*get_unit_number(t_list *list, int number);
t_unit			*get_unit_s_index(t_list *list, int number);
t_unit			*get_min_unit(t_list *a);
t_unit			*get_max_unit(t_list *a);
t_unit			*get_unit_quarter(t_list *a, int quarter_limit);
t_unit			*get_max_unit_quarter(t_list *a, int quarter_limit);
void			push(t_list **a, t_list **b, t_list **operation, char *op);
void			swap(t_list **a, t_list **operation, char *op);
void			rotate(t_list **a, t_list **operation, char *op);
void			rrotate(t_list **a, t_list **operation, char *op);
void			case_213(t_list **a, t_list **op, int stack);
void			case_321(t_list **a, t_list **op, int stack);
void			case_312(t_list **a, t_list **op, int stack);
void			case_132(t_list **a, t_list **op, int stack);
void			case_231(t_list **a, t_list **op, int stack);
void			median_rotate(t_list **a, int num, t_list **op_list, int stack);
int				is_list_sorted(t_list *a);
int				handler_case_3(t_list **a, t_list **op_list, int stack);
int				logic(t_list **a, t_list **b, t_list **op_list, int key_nbr);
int				is_successor(int a, int b);
int				is_top_3_successor(t_list **a);
t_list			*init_stack(int ac, char **av);
t_unit			*init_new_unit(char *str_digit, unsigned int sorted_index);
void			add_op(t_list **operation, char *op_name);
void			clear_exit(t_list **stack_a,
					t_list **stack_b, t_list **op_list);
void			checker_logic(t_list **a, t_list **b, t_list **op_list);
int				checker_dispatch(t_list **a, t_list **b, char *op_arg);
int				checker_make_op_list(t_list **a, t_list **b, t_list **op_list);
int				is_op_arg_valid(char *op_arg);
//DEBUG
void			print_debug(t_list **a, t_list **b);
void			print_operation(t_list **op_list);

#endif
