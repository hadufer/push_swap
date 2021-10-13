/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:20:38 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/12 22:19:42 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	delete_unit(void *unit)
{
	if (unit)
		free(unit);
	unit = NULL;
}

t_unit	*new_unit(int number, int sorted_index)
{
	t_unit	*out;

	out = malloc(sizeof(out));
	if (!out)
		return (NULL);
	out->number = number;
	out->sorted_index  = sorted_index;
	return (out);
}
