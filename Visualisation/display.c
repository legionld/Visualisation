/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:11:03 by jschille          #+#    #+#             */
/*   Updated: 2019/06/29 14:38:43 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		draw_point(t_unint *data, int x, int y, t_unint clr)
{
	data[x * WIDTH + y] = clr;
}

static int		check_limits(int x0, int y0)
{
	if (x0 >= RADIUS &&
	y0 >= RADIUS &&
	x0 < (HIGHT - RADIUS) &&
	y0 < (WIDTH - RADIUS))
		return (1);
	return (0);
}

static void		draw_circle(t_unint *data, int x0, int y0, t_unint clr)
{
	int		x;
	int		y;
	int		r_error;

	x = RADIUS;
	y = 0;
	r_error = 1 - x;
	while (x >= y++ && check_limits(x0, y0))
	{
		draw_point(data, x + x0, y + y0, clr);
		draw_point(data, y + x0, x + y0, clr);
		draw_point(data, -x + x0, y + y0, clr);
		draw_point(data, -y + x0, x + y0, clr);
		draw_point(data, -x + x0, -y + y0, clr);
		draw_point(data, -y + x0, -x + y0, clr);
		draw_point(data, x + x0, -y + y0, clr);
		draw_point(data, y + x0, -x + y0, clr);
		if (r_error < 0)
			r_error += 2 * y + 1;
		else
		{
			x--;
			r_error += 2 * (y - x + 1);
		}
	}
}

void			trace_point(t_env *env, t_mlx *mlx)
{
	t_list	*lst;
	t_list	*tmp;
	t_room	*room;
	t_point	a;
	t_point	b;

	lst = env->list;
	while (lst)
	{
		draw_circle(mlx->img_data, ((t_room*)lst->content)->coords[0],
		((t_room*)lst->content)->coords[1], ((t_room*)lst->content)->clr);
		room = (t_room*)lst->content;
		tmp = room->links;
		a.x = room->coords[1];
		a.y = room->coords[0];
		while (tmp)
		{
			b.x = ((t_room*)tmp->content)->coords[1];
			b.y = ((t_room*)tmp->content)->coords[0];
			draw_line(mlx->img_data, a, b);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

void			display_out(t_env *env)
{
	t_mlx	*mlx;

	mlx = set_data(env);
	set_mid(mlx, env);
	trace_point(env, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	hooker(mlx);
	mlx_loop(mlx->mlx_ptr);
}
