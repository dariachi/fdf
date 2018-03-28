/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 12:02:01 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/10 17:22:12 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_w(char const *str, char c, char cc)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] != c && str[i] != cc) && (str[i + 1] == c ||
			str[i + 1] == cc || str[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}

char	**coord_z(char const *s, char c, char cc)
{
	int		i;
	int		j;
	int		start;
	char	**res;

	i = 0;
	j = 0;
	if ((res = (char**)malloc(sizeof(char*) * (ft_w(s, c, cc) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		if (i == 0 || ((s[i] != c && s[i] != cc) &&
			(s[i - 1] == c || s[i - 1] == cc)))
			start = i;
		if (s[i] != c && s[i] != cc && (s[i + 1] == c
			|| s[i + 1] == cc || s[i + 1] == '\0'))
		{
			res[j] = ft_strsub(s, (unsigned int)start, (size_t)i - start + 1);
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
