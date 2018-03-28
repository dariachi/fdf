/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_sr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:53:10 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/11 15:51:44 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_all		*ft_zum(t_all *all, int i)
{
	double		zoom;
	double		p_r;

	zoom = 950 / all->count_x;
	p_r = 950 / all->count_y;
	if (p_r < zoom)
		zoom = p_r;
	if (zoom > i)
		all->zoom = i;
	else
	{
		if (zoom < 16 && zoom > 4)
			all->zoom = zoom - 4;
		else
			all->zoom = zoom;
	}
	return (all);
}

t_coord		creat_coord(t_all *all, int z, int collor)
{
	t_coord	coord;

	coord.x = (all->x - all->count_x / 2);
	coord.y = (all->y - all->count_y / 2);
	coord.z_for_color = z;
	coord.z = z;
	coord.collor = collor;
	if (z > all->max_z)
		all->max_z = z;
	if (z < all->min_z)
		all->min_z = z;
	return (coord);
}

t_all		*ft_push_win(t_all *all)
{
	all->y = 0;
	all->x = 0;
	mlx_clear_window(all->mlx, all->win);
	while (all->y < all->count_y)
	{
		all->x = 0;
		while (all->x < all->count_x)
		{
			p_coord(all);
			all->x++;
		}
		all->y++;
	}
	return (all);
}

void		ft_fdf(char *str, t_all *all)
{
	all->count_y = ft_count_y(str);
	all->max_z = 0;
	all->r = 0;
	all->ia = 0;
	all->ib = 0;
	all->lllccc = 0;
	ft_zum(all, 20);
	ft_creat_mass(all, str);
	if (all->max_z > 20 || all->min_z > 20)
		ft_zum(all, 6);
	ft_izometr(all);
	if (!(all->mlx = mlx_init()))
		return ;
	all->win = mlx_new_window(all->mlx, 1200, 1200, "fdf");
	ft_push_win(all);
	mlx_hook(all->win, 2, 5, key_down, all);
	mlx_mouse_hook(all->win, mouse_color, all);
	mlx_loop(all->mlx);
}

int			main(int argc, char **argv)
{
	int			fd;
	char		*str;
	t_all		*all;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!fd || (!argv) || fd == 0 || fd == -1)
		{
			ft_putstr("error: files");
			return (0);
		}
		if (!(str = (char *)malloc(sizeof(char) * 8000000 + 1)))
			return (ft_malloc_error(0));
		read(fd, str, 8000001);
		all = (t_all *)malloc(sizeof(t_all));
		all->count_x = ft_count_x(str, 0, 0, 0);
		if (all->count_x == -2 || all->count_x == 0)
			return (ft_error(all->count_x));
		ft_fdf(str, all);
		close(fd);
	}
	else
		ft_putstr("error: one argument!");
	return (0);
}
