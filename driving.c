/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:11:42 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/10 16:51:12 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_all	*ft_verh(t_all *all, int keycode)
{
	if (keycode == 126)
		all->ib -= 5;
	if (keycode == 125)
		all->ib += 5;
	if (keycode == 123)
		all->ia -= 5;
	if (keycode == 124)
		all->ia += 5;
	ft_push_win(all);
	return (all);
}

t_all	*ft_pov_z_down(t_all *all)
{
	double	cop_x;
	double	cop_y;
	double	cop_z;
	double	l;

	l = (3 * M_PI) / 180;
	all->y = 0;
	while (all->y < all->count_y)
	{
		all->x = 0;
		while (all->x < all->count_x)
		{
			cop_x = all->mass[all->y][all->x].x;
			cop_y = all->mass[all->y][all->x].y;
			cop_z = all->mass[all->y][all->x].z;
			all->mass[all->y][all->x].x = cop_x * cos(l) + (cop_y * sin(l));
			all->mass[all->y][all->x].y = cop_x * (-sin(l)) + cop_y * cos(l);
			all->x++;
		}
		all->y++;
	}
	ft_izometr(all);
	ft_push_win(all);
	return (all);
}
