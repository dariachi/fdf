/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:47:47 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/04 17:50:45 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_all	*ft_pov_x(t_all *all)
{
	all->l = (3 * M_PI) / 180;
	all->y = 0;
	while (all->y < all->count_y)
	{
		all->x = 0;
		while (all->x < all->count_x)
		{
			all->cop_x = all->mass[all->y][all->x].x;
			all->cop_y = all->mass[all->y][all->x].y;
			all->cop_z = all->mass[all->y][all->x].z;
			all->mass[all->y][all->x].y = (all->cop_y * cos(all->l) +
				all->cop_z * (-sin(all->l)));
			all->mass[all->y][all->x].z = (all->cop_y * sin(all->l) +
				all->cop_z * cos(all->l));
			all->x++;
		}
		all->y++;
	}
	ft_izometr(all);
	ft_push_win(all);
	return (all);
}

t_all	*ft_pov_x_down(t_all *all)
{
	double		cop_x;
	double		cop_y;
	double		cop_z;
	double		l;

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
			all->mass[all->y][all->x].y = (cop_y * cos(l) + cop_z * sin(l));
			all->mass[all->y][all->x].z = (cop_y * (-sin(l)) + cop_z * cos(l));
			all->x++;
		}
		all->y++;
	}
	ft_izometr(all);
	ft_push_win(all);
	return (all);
}

t_all	*ft_pov_y(t_all *all)
{
	all->l = (3 * M_PI) / 180;
	all->y = 0;
	while (all->y < all->count_y)
	{
		all->x = 0;
		while (all->x < all->count_x)
		{
			all->cop_x = all->mass[all->y][all->x].x;
			all->cop_y = all->mass[all->y][all->x].y;
			all->cop_z = all->mass[all->y][all->x].z;
			all->mass[all->y][all->x].x = all->cop_x * cos(all->l) +
				all->cop_z * sin(all->l);
			all->mass[all->y][all->x].z = all->cop_x * (-sin(all->l)) +
				all->cop_z * cos(all->l);
			all->x++;
		}
		all->y++;
	}
	ft_izometr(all);
	ft_push_win(all);
	return (all);
}

t_all	*ft_pov_y_down(t_all *all)
{
	all->l = (3 * M_PI) / 180;
	all->y = 0;
	while (all->y < all->count_y)
	{
		all->x = 0;
		while (all->x < all->count_x)
		{
			all->cop_x = all->mass[all->y][all->x].x;
			all->cop_y = all->mass[all->y][all->x].y;
			all->cop_z = all->mass[all->y][all->x].z;
			all->mass[all->y][all->x].x = all->cop_x * cos(all->l) +
				all->cop_z * -(sin(all->l));
			all->mass[all->y][all->x].z = all->cop_x * sin(all->l) +
				all->cop_z * cos(all->l);
			all->x++;
		}
		all->y++;
	}
	ft_izometr(all);
	ft_push_win(all);
	return (all);
}

t_all	*ft_pov_z(t_all *all)
{
	double		cop_x;
	double		cop_y;
	double		cop_z;
	double		l;

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
			all->mass[all->y][all->x].x = cop_x * cos(l) + (cop_y * (-sin(l)));
			all->mass[all->y][all->x].y = cop_x * sin(l) + cop_y * cos(l);
			all->x++;
		}
		all->y++;
	}
	ft_izometr(all);
	ft_push_win(all);
	return (all);
}
