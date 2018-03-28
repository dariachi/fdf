/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbrf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:32:31 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/12 11:01:05 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_all	*ft_coord_b(int x2, int y2, t_all *all)
{
	all->x1 = all->iz_mass[all->y][all->x].x;
	all->y1 = all->iz_mass[all->y][all->x].y;
	all->x2 = x2;
	all->y2 = y2;
	all->delx = (all->x2 - all->x1);
	if (all->delx < 0)
		all->delx *= -1;
	all->dely = (all->y2 - all->y1);
	if (all->dely < 0)
		all->dely *= -1;
	if (all->x1 < all->x2)
		all->sx = 1;
	else
		all->sx = -1;
	if (all->y1 < all->y2)
		all->sy = 1;
	else
		all->sy = -1;
	all->dd = all->delx - all->dely;
	return (all);
}

int		ft_collor(int collor, t_all *all)
{
	if (collor == 65535 || collor == 16711935)
		collor = all->iz_mass[all->y][all->x].collor;
	return (collor);
}

t_all	*algorbrez(int x2, int y2, t_all *all, int collor)
{
	ft_coord_b(x2, y2, all);
	while (all->x1 != all->x2 || all->y1 != all->y2)
	{
		if (collor != all->iz_mass[all->y][all->x].collor)
			collor = ft_collor(collor, all);
		all->k_x = all->x1 + all->ia + 600 + (all->max_z + all->min_z) / 2;
		all->k_y = all->y1 + all->ib + 600;
		if (all->k_x >= 10 && all->k_x <= 1190 &&
				all->k_y >= 10 && all->k_y <= 1190)
			mlx_pixel_put(all->mlx, all->win, all->k_x, all->k_y, collor);
		all->e = all->dd * 2;
		if (all->e > -all->dely)
		{
			all->dd -= all->dely;
			all->x1 += all->sx;
		}
		if (all->e < all->delx)
		{
			all->dd += all->delx;
			all->y1 += all->sy;
		}
	}
	return (all);
}

t_all	*p_coord(t_all *all)
{
	int x;

	if (all->x + 1 < all->count_x)
	{
		x = all->iz_mass[all->y][all->x + 1].x;
		algorbrez(x, all->iz_mass[all->y][all->x + 1].y,
			all, all->iz_mass[all->y][all->x + 1].collor);
	}
	if (all->y + 1 < all->count_y)
	{
		x = all->iz_mass[all->y + 1][all->x].x;
		algorbrez(x, all->iz_mass[all->y + 1][all->x].y,
			all, all->iz_mass[all->y + 1][all->x].collor);
	}
	return (all);
}
