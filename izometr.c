/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   izometr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 12:22:58 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/12 10:51:27 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_search_neg(t_all *all)
{
	int			time;
	int			num;

	num = 0;
	time = 255 / all->min_z;
	num = time * (-255);
	return (num);
}

t_izcoord	dif_cord(t_all *all)
{
	t_izcoord	izc;

	izc.z = all->mass[all->y][all->x].z * all->zoom;
	izc.y = (all->mass[all->y][all->x].x + (2 * all->mass[all->y][all->x].y) +
		all->mass[all->y][all->x].z) / sqrt(6) * all->zoom;
	izc.x = (all->mass[all->y][all->x].x - all->mass[all->y][all->x].z) *
		((sqrt(3) / sqrt(6)) * all->zoom);
	if (all->lllccc != 0)
		izc.collor = all->lllccc;
	else if (all->mass[all->y][all->x].collor != 0)
		izc.collor = all->mass[all->y][all->x].collor;
	else
	{
		if (all->mass[all->y][all->x].z_for_color == 0)
			izc.collor = 16776960;
		else if (all->mass[all->y][all->x].z_for_color == all->max_z)
			izc.collor = 65535;
		else if (all->mass[all->y][all->x].z_for_color == all->min_z)
			izc.collor = 16711935;
		else
			izc.collor = 16776960;
	}
	return (izc);
}

t_all		*ft_izometr(t_all *all)
{
	all->y = 0;
	all->x = 0;
	all->iz_mass = (t_izcoord **)malloc(sizeof(t_izcoord *) * all->count_y);
	while (all->y < all->count_y)
	{
		all->iz_mass[all->y] = (t_izcoord *)malloc(sizeof(t_izcoord) *
			all->count_x);
		all->x = 0;
		while (all->x < all->count_x)
		{
			all->iz_mass[all->y][all->x] = dif_cord(all);
			all->x++;
		}
		all->y++;
	}
	return (all);
}
