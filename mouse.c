/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:16:09 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/12 10:20:22 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_color(int mouse, int x8, int y8, t_all *all)
{
	x8 = 0;
	y8 = 0;
	all->lllccc = 0;
	if (mouse == 1)
	{
		all->r += 1;
		if (all->r == 1)
			all->lllccc = 255;
		else if (all->r == 2)
			all->lllccc = 65280;
		else if (all->r == 3)
			all->lllccc = 16711680;
		if (all->r == 3)
			all->r = 0;
	}
	if (mouse == 2)
		all->lllccc = 0;
	mlx_clear_window(all->mlx, all->win);
	ft_izometr(all);
	ft_push_win(all);
	return (20);
}
