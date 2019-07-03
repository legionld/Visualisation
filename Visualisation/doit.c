/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 07:49:11 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 07:53:24 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HIGHT);
	mlx->img_data = (t_unint*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
		&mlx->size_line, &mlx->alpha);
}

void	re_draw(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	if (mlx->line)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0xFFFFFF, mlx->line);
}

void	do_it(int keycode, t_mlx *img, t_env *env)
{
	if (keycode == 53)
	{
		clean(img);
		err_out(-1, NULL, env);
	}
	if (keycode == 126)
		scale_h_up(img, env);
	if (keycode == 125)
		scale_h_down(img, env);
	if (keycode == 124)
		scale_w_up(img, env);
	if (keycode == 123)
		scale_w_down(img, env);
	if (keycode == 49)
		next_step(img, env);
	else
		trace_point(env, img);
}
