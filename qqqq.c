/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qqqq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:20:47 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/12 10:52:08 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_all		*ft_creat_mass(t_all *all, char *str)
{
	all->mass = ft_create_map(all, str, 0, 0);
	return (all);
}

t_coord		**ft_create_map(t_all *all, char *str, int r, int z)
{
	t_coord		**map;
	char		**m_z;
	char		*collor;

	m_z = coord_z(str, ' ', '\n');
	all->y = 0;
	collor = (char *)malloc(sizeof(char) * 10);
	map = (t_coord **)malloc(sizeof(t_coord *) * (all->count_y));
	while (all->y < all->count_y)
	{
		map[all->y] = (t_coord *)malloc(sizeof(t_coord) * all->count_x);
		all->x = 0;
		while (all->x < all->count_x)
		{
			collor = m_z[r];
			z = 0;
			if (ft_strchr(m_z[r], ',') != NULL)
				z = ft_itoa_mode(m_z[r]);
			map[all->y][all->x] = creat_coord(all, ft_atoi(collor), z);
			all->x++;
			r++;
		}
		all->y++;
	}
	return (map);
}

int			ft_error(int m)
{
	if (m == -2)
		ft_putstr("error: not a valid map");
	if (m == 0)
		ft_putstr("error: no map!");
	return (0);
}

int			ft_malloc_error(int i)
{
	ft_putstr("malloc error");
	return (i);
}
