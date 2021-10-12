/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:37:35 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/12 20:34:35 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_unit	*init_new_unit(char *str_digit, unsigned int sorted_index)
{
	t_unit	*out;
	char	*trimed_str_digit;

	out = malloc(sizeof(out));
	if (out == NULL)
		return (NULL);
	trimed_str_digit = ft_strtrim(str_digit, " \t\n\v\f\r");
	out->number = ft_atoi(trimed_str_digit);
	free(trimed_str_digit);
	out->sorted_index = sorted_index;
	return (out);
}

t_list	*init_list(int ac, char **av)
{
	t_list			*out;
	t_unit			*tmp_u;
	char			*trimed_str;
	unsigned int	i;

	i = 1;
	trimed_str = ft_strtrim(av[i], " \t\n\v\f\r");
	out = ft_lstnew(init_new_unit(av[i], i - 1));
	free(trimed_str);
	if (!out)
		return (NULL);
	i++;
	while (i < (unsigned int)ac)
	{
		tmp_u = init_new_unit(av[i], i - 1);
		if (tmp_u == NULL)
			return (NULL);
		ft_lstadd_back(&out, ft_lstnew(tmp_u));
		i++;
	}
	return (out);
}

void	clear_exit(t_list *stack_a, t_list *stack_b)
{
	if (stack_a)
		ft_lstclear(&stack_a, delete_unit);
	if (stack_b)
		ft_lstclear(&stack_b, delete_unit);
	exit(0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if ((ac < 2) || parse_entry(ac, av) == -1)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_a = init_list(ac, av);
	stack_b = NULL;
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	list_quick_sort(stack_a, 0, list_get_size(stack_a));
	// DEBUG
	t_list *tmp = stack_a;
	while (tmp)
	{
		ft_printf("index:%d = value:%d\n", ((t_unit *)(tmp->content))->sorted_index, ((t_unit *)(tmp->content))->number);
		tmp = tmp->next;
	}
	clear_exit(stack_a, stack_b);
}
