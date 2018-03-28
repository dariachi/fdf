/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:29:48 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/16 15:23:49 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wcount(char const *str, char c)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}