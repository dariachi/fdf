/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coun_in_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:04:41 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/10 17:28:46 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_coun_in_w(char *s, char c, int z)
{
	int		p;
	int		x;

	p = 0;
	x = 0;
	while ((s[p] != '\0') && z)
	{
		x = 0;
		if (s[p] != c)
		{
			while (s[p] != c && s[p] != '\0')
			{
				x++;
				p++;
			}
			z--;
		}
		else
			p++;
	}
	return (x);
}