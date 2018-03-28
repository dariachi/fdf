/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:08:46 by dchirkin          #+#    #+#             */
/*   Updated: 2017/04/12 11:10:36 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct			s_coord
{
	double				x;
	double				y;
	double				z;
	double				z_for_color;
	int					collor;
	struct s_letter		*next;
}						t_coord;

typedef struct			s_izcoord
{
	double				x;
	double				y;
	double				z;
	int					collor;
	struct s_izcoord	*next;
}						t_izcoord;

typedef struct			s_all
{
	double				k_x;
	double				k_y;
	int					e;
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					delx;
	int					dely;
	int					sx;
	int					sy;
	int					dd;
	int					lllccc;
	int					ia;
	int					ib;
	int					r;
	t_coord				**mass;
	t_izcoord			**iz_mass;
	int					count_x;
	int					count_y;
	int					x;
	int					y;
	double				l;
	void				*mlx;
	void				*img;
	void				*win;
	void				*ptr;
	double				cop_x;
	double				cop_y;
	double				cop_z;
	double				zoom;
	int					max_z;
	int					min_z;
	struct s_all		*next;
}						t_all;

int						ft_w(char const *str, char c, char cc);
int						ft_cheak(char c, char next_c);
t_all					*ft_coord_b(int x2, int y2, t_all *all);
int						ft_collor(int collor, t_all *all);
t_all					*ft_zum(t_all *all, int i);
void					ft_fdf(char *str, t_all *all);
int						ft_search_neg(t_all *all);
int						ft_error(int m);
int						ft_malloc_error(int i);
t_all					*ft_poisk(t_all *all);
int						ft_expose(int expose, int x, int y, t_all *all);
t_all					*ft_pov_z_down(t_all *all);
t_all					*ft_pov_y_down(t_all *all);
t_all					*ft_pov_z(t_all *all);
t_all					*ft_pov_y(t_all *all);
t_all					*ft_pov_x_down(t_all *all);
t_all					*ft_pov_x(t_all *all);
int						ft_itoa_mode(char *str);
char					*ft_search_collor(char *str);
t_all					*ft_verh(t_all *all, int keycode);
t_all					*ft_center(t_all *all);
t_all					*ft_push_win(t_all *all);
t_all					*ft_pov_x(t_all *all);
int						key_down(int key, t_all *all);
t_all					*algorbrez(int x2, int y2, t_all *all, int collor);
t_all					*p_coord(t_all *all);
char					**coord_z(char const *s, char c, char cc);
t_coord					**ft_create_map(t_all *all, char *str, int r, int z);
char					*ft_search_color(char *str);
t_coord					creat_coord(t_all *all, int z, int collor);
int						ft_count_x(char *str, int r, int i, int l);
int						ft_count_y(char *str);
t_all					*ft_izometr(t_all *all);
t_izcoord				dif_cord(t_all *all);
t_all					*ft_creat_mass(t_all *all, char *str);
int						mouse_color(int mouse, int xe, int ye, t_all *all);
t_all					*ft_umen(t_all *all);
t_all					*ft_uvel(t_all *all);

#endif
