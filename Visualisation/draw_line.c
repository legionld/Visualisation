/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:44:07 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 08:04:57 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int		mabs(int n)
{
	if (n == -2147483648)
		return (2147483647);
	if (n < 0)
		return (n * -1);
	return (n);
}

static void		set_pixel(t_unint *data, int x, int y)
{
	data[x * WIDTH + y] = 0xFFFFFF;
}

static void		init_delta(int *delta, t_point a, t_point b)
{
	delta[0] = mabs(b.x - a.x);
	delta[1] = mabs(b.y - a.y);
	delta[2] = a.x < b.x ? 1 : -1;
	delta[3] = a.y < b.y ? 1 : -1;
	delta[4] = delta[0] - delta[1];
}

void			draw_line(t_unint *data, t_point a, t_point b)
{
	int		delta[6];

	init_delta(delta, a, b);
	if (b.x >= 0 && b.y >= 0 && b.x < WIDTH && b.y < HIGHT)
		set_pixel(data, b.y, b.x);
	while ((a.x != b.x || a.y != b.y) && a.x < WIDTH &&
	a.y < HIGHT && a.x >= 0 && a.y >= 0)
	{
		if (a.x >= 0 && a.y >= 0)
			set_pixel(data, a.y, a.x);
		delta[5] = delta[4] * 2;
		if (delta[5] > -delta[1])
		{
			delta[4] -= delta[1];
			a.x += delta[2];
		}
		if (delta[5] < delta[0])
		{
			delta[4] += delta[0];
			a.y += delta[3];
		}
	}
}

void	set_extrem(t_mlx *mlx, int	*max_min)
{
	float	max_y;
	float	max_x;

	max_y = max_min[2] - max_min[0];
	max_x = max_min[3] - max_min[1];
	max_y < 0 ? max_y *= -1 : max_y;
	max_x < 0 ? max_x *= -1 : max_x;
	if (max_y > max_x)
		mlx->scale = (WIDTH - WIDTH / 2) / (max_y);
	else
		mlx->scale = (HIGHT - HIGHT / 2) / (max_x);
	mlx->half_x = WIDTH / 2;
	mlx->half_y = HIGHT / 2;
}
