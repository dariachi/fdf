/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:46:17 by dchirkin          #+#    #+#             */
/*   Updated: 2017/12/07 16:46:23 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:45:35 by dchirkin          #+#    #+#             */
/*   Updated: 2017/12/07 16:45:57 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:45:25 by dchirkin          #+#    #+#             */
/*   Updated: 2017/12/07 16:45:25 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:38:03 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/11 15:52:26 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_all	*ft_uvel(t_all *all)
{
	all->y = 0;
	while (all->y < all->count_y)
	{
		all->x = 0;
		while (all->x < all->count_x)
		{
			all->mass[all->y][all->x].x =
				(all->mass[all->y][all->x].x / all->zoom) * (all->zoom + 0.5);
			all->mass[all->y][all->x].y =
				(all->mass[all->y][all->x].y / all->zoom) * (all->zoom + 0.5);
			all->mass[all->y][all->x].z =
				(all->mass[all->y][all->x].z / all->zoom) * (all->zoom + 0.5);
			all->x++;
		}
		all->y++;
	}
	ft_izometr(all);
	ft_push_win(all);
	return (all);
}

t_all	*ft_umen(t_all *all)
{
	all->y = 0;
	while (all->y < all->count_y)
	{
		all->x = 0;
		while (all->x < all->count_x)
		{
			all->mass[all->y][all->x].x =
			(all->mass[all->y][all->x].x / all->zoom) * (all->zoom - 0.5);
			all->mass[all->y][all->x].y =
			(all->mass[all->y][all->x].y / all->zoom) * (all->zoom - 0.5);
			all->mass[all->y][all->x].z =
			(all->mass[all->y][all->x].z / all->zoom) * (all->zoom - 0.5);
			all->x++;
		}
		all->y++;
	}
	ft_izometr(all);
	ft_push_win(all);
	return (all);
}

int		key_down(int key, t_all *all)
{
	if (key == 53)
	{
		free(all->mass);
		free(all->iz_mass);
		exit(0);
	}
	if (key == 7)
		ft_pov_x(all);
	if (key == 16)
		ft_pov_y(all);
	if (key == 12)
		ft_pov_x_down(all);
	if (key >= 123 && key <= 126)
		ft_verh(all, key);
	if (key == 6)
		ft_pov_z(all);
	if (key == 13)
		ft_pov_y_down(all);
	if (key == 14)
		ft_pov_z_down(all);
	if (key == 69)
		ft_uvel(all);
	if (key == 78)
		ft_umen(all);
	return (0);
}
