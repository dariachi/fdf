/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:44:31 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/10 16:53:00 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_itoa_mode(char *str)
{
	int		t;
	int		cof;
	int		j;
	int		num;

	t = 0;
	j = ft_strlen(str) - 1;
	cof = 1;
	num = 0;
	while (str[j] && cof <= 1048576)
	{
		if (str[j] >= '0' && str[j] <= '9')
			t = str[j] - '0';
		if (str[j] >= 'A' && str[j] <= 'F')
			t = str[j] - 'A' + 10;
		if (str[j] >= 'a' && str[j] <= 'f')
			t = str[j] - 'a' + 10;
		num = num + (cof * t);
		cof *= 16;
		j--;
	}
	return (num);
}
