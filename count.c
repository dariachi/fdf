/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:32:07 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/12 10:50:58 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_coccc(char s, char s_p)
{
	if (s_p == ' ' || s_p == '\n')
	{
		if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
			return (-2);
	}
	return (1);
}

int		ft_cheak(char c, char next_c)
{
	if (((c >= '0' && c <= '9') || (c >= 'a' &&
		c <= 'z') || (c >= 'A' && c <= 'Z')) &&
		(next_c == '\n' || next_c == ' ' || next_c == '\0'))
		return (1);
	else
		return (0);
}

int		ft_l(int l, int r, char st)
{
	if (l != r)
		return (-2);
	l = 0;
	if (st == '\0')
		return (r);
	return (0);
}

int		ft_count_x(char *str, int r, int i, int l)
{
	if (str[0] == '\0' || (str[0] <= '0' && str[0] >= '9' && str[0] != ' '))
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (i != 0)
			if (ft_coccc(str[i], str[i - 1]) == -2)
				return (-2);
		if (ft_cheak(str[i], str[i + 1]) == 1)
			r++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_cheak(str[i], str[i + 1]) == 1)
			l++;
		if (ft_coccc(str[i], str[i - 1]) == -2)
			return (-2);
		if (str[i + 1] == '\n' || str[i + 1] == '\0')
		{
			if ((l = ft_l(l, r, str[i + 2])) != 0)
				return (l);
		}
		i++;
	}
	return (r);
}

int		ft_count_y(char *str)
{
	int		c;
	int		j;

	c = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '\n' || str[j + 1] == '\0')
			c++;
		j++;
	}
	return (c);
}
