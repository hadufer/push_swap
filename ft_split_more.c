/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:30:02 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/09 15:14:57 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	count_word(char	*str, char *c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_strchr(c, str[i]))
		{
			while (str[i] && !ft_strchr(c, str[i]))
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_strlen_c(const char *str, char *c)
{
	int	i;

	i = 0;
	while (str[i] && !ft_strchr(c, str[i]))
		i++;
	return (i);
}

static void	clear_ret(char **ret, int i)
{
	while (i >= 0)
	{
		free(ret[i]);
		ret[i] = NULL;
		i--;
	}
	free(ret);
}

static int	ft_split_utils(int tab[5], char *str, char **ret)
{
	if (tab[3])
	{
		ret[tab[1]] = malloc(sizeof(char) * (tab[3] + 1));
		if (!ret[tab[1]])
			return (0);
		tab[2] = 0;
		while (tab[2] < tab[3])
		{
			ret[tab[1]][tab[2]] = str[tab[0]];
			tab[0]++;
			tab[2]++;
		}
		ret[tab[1]][tab[2]] = 0;
		tab[1]++;
	}
	else
		tab[0]++;
	return (1);
}

char	**ft_split_more(char const *str, char *c, int *len)
{
	int		tab[5];
	char	**ret;

	tab[0] = 0;
	tab[1] = 0;
	*len = count_word((char *)str, c);
	tab[4] = count_word((char *)str, c);
	ret = malloc(sizeof(char *) * (tab[4] + 1));
	if (!ret)
		return (NULL);
	while (tab[1] < tab[4])
	{
		tab[3] = ft_strlen_c(str + tab[0], c);
		if (!ft_split_utils(tab, (char *)str, ret))
		{
			clear_ret(ret, tab[1]);
			return (NULL);
		}
	}
	ret[tab[1]] = NULL;
	return (ret);
}
