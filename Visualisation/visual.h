/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:11:11 by jschille          #+#    #+#             */
/*   Updated: 2019/06/29 21:33:27 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
# include "libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# define HIGHT 1080
# define WIDTH 1920
# define SCALE 1.5
# define RADIUS 10

typedef unsigned int	t_unint;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_room
{
	char			*name;
	t_unint			index;
	t_list			*links;
	int				coords[2];
	t_unint			clr;
	char			soe;
}				t_room;

typedef struct	s_ant
{
	t_unint	name;
	t_room 	*room;
}				t_ant;

typedef struct	s_env
{
	t_unint			ants;
	t_list			*list;
	t_list			*start;
	t_list			*end;
	t_list			*lants;
}				t_env;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*line;
	t_unint	*img_data;
	t_env	*env;
	int		bpp;
	int		size_line;
	int		alpha;
	int		half_y;
	int		half_x;
	float	scale;
	int		pres_m;
	int		pres_x;
	int		pres_y;
	int		extrem[4];
}				t_mlx;

t_mlx			*set_data(t_env *env);
t_env			*parser(void);
void			ft_error(t_env *e);
t_room			*get_room(char *line, t_env **env, short comm);
void			set_links(char *line, t_env **env);
void			put_link(t_env *env, t_room **room, char *name);
void			set_ants(char *line, t_env **env);
void			set_lants(t_env **env);
void			parser_comment(char *line, t_env **env);
void			set_rooms(char *line, t_env **env, t_unint clr);
void			err_out(int e, char *line, t_env *env);
void			display_out(t_env *env);
void			draw_line(t_unint *data, t_point a, t_point b);
void			hooker(t_mlx *mlx);
void			trace_point(t_env *env, t_mlx *mlx);

void			set_mid(t_mlx *mlx, t_env *env);
void			scale_d(t_mlx *img, t_env *env, float scale);

void			move_mid(t_mlx *img, t_env *env);
void			move_back(t_mlx *img, t_env *env);
void			scale_up(t_mlx *img, t_env *env);
void			scale_down(t_mlx *img, t_env *env);
void			next_step(t_mlx *img, t_env *env);
void			scale_h_up(t_mlx *img, t_env *env);
void			scale_h_down(t_mlx *img, t_env *env);
void			scale_w_up(t_mlx *img, t_env *env);
void			scale_w_down(t_mlx *img, t_env *env);

void			move_left(t_mlx *img, t_env *env);
void			move_right(t_mlx *img, t_env *env);
void			move_up(t_mlx *img, t_env *env);
void			move_down(t_mlx *img, t_env *env);
void			move_img(t_mlx *img, t_env *env, int x, int y);

int			key_press(int keycode, t_mlx *img);
int			mouse_move(int x, int y, t_mlx *img);
int			mouse_pres(int btn, int x,int y, t_mlx *img);
int			mouse_releas(int btn, int x,int y, t_mlx *img);

#endif
