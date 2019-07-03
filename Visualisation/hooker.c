/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 03:19:21 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 07:55:31 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int			key_press(int keycode, t_mlx *img)
{
	t_env			*env;

	env = img->env;
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	img->img_ptr = mlx_new_image(img->mlx_ptr, WIDTH, HIGHT);
	img->img_data = (t_unint*)mlx_get_data_addr(img->img_ptr, &img->bpp,
		&img->size_line, &img->alpha);
	do_it(keycode, img, env);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	if (img->line)
		mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 10, 0xFFFFFF, img->line);
	return (0);
}

int			mouse_move(int x, int y, t_mlx *img)
{
	t_env			*env;

	env = img->env;
	if (img->pres_m == 1)
	{
		destroy(img);
		move_img(img, env, x - img->pres_x, y - img->pres_y);
		img->pres_y = y;
		img->pres_x = x;
		re_draw(img);
	}
	return (0);
}

int			mouse_pres(int btn, int x, int y, t_mlx *img)
{
	t_env			*env;

	env = img->env;
	if (btn == 1)
	{
		img->pres_m = 1;
		img->pres_x = x;
		img->pres_y = y;
	}
	if (btn == 4)
	{
		destroy(img);
		scale_up(img, env);
		re_draw(img);
	}
	if (btn == 5)
	{
		destroy(img);
		scale_down(img, env);
		re_draw(img);
	}
	return (0);
}

int			mouse_releas(int btn, int x, int y, t_mlx *img)
{
	t_env			*env;

	env = img->env;
	x = y;
	if (btn == 1)
		img->pres_m = 0;
	return (0);
}

void		hooker(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_pres, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_releas, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
}
