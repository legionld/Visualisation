/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaleble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:36:08 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 08:05:59 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	set_mid(t_mlx *mlx, t_env *env)
{
	int		max_min[4];
	t_list	*lst;
	t_list	*tmp;

	lst = env->list;
	max_min[0] = ((t_room*)lst->content)->coords[1];
	max_min[1] = ((t_room*)lst->content)->coords[0];
	while (lst)
	{
		if (((t_room*)lst->content)->coords[0] > max_min[1])
			max_min[1] = ((t_room*)lst->content)->coords[0];
		if (((t_room*)lst->content)->coords[1] > max_min[0])
			max_min[0] = ((t_room*)lst->content)->coords[1];
		// if (((t_room*)lst->content)->coords[0] < max_min[3])
		// 	max_min[3] = ((t_room*)lst->content)->coords[0];
		// if (((t_room*)lst->content)->coords[1] < max_min[2])
		// 	max_min[2] = ((t_room*)lst->content)->coords[1];
		tmp = ((t_room*)env->list->content)->links;
		lst = lst->next;
	}
	mlx->half_x = max_min[0] / 2;
	mlx->half_y = max_min[1] / 2;
	move_mid(mlx, env);
	set_extrem(mlx, max_min);
	move_back(mlx, env);
	scale_d(mlx, env, mlx->scale);
}

void	move_mid(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	while (env->list)
	{
		((t_room*)env->list->content)->coords[0] -= img->half_y;
		((t_room*)env->list->content)->coords[1] -= img->half_x;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[0] -= img->half_y;
			((t_room*)tmp->content)->coords[1] -= img->half_x;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
}

void	move_back(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	while (env->list)
	{
		((t_room*)env->list->content)->coords[0] += img->half_y;
		((t_room*)env->list->content)->coords[1] += img->half_x;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[0] += img->half_y;
			((t_room*)tmp->content)->coords[1] += img->half_x;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
}

void	scale_up(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	move_mid(img, env);
	while (env->list)
	{
		((t_room*)env->list->content)->coords[0] *= SCALE;
		((t_room*)env->list->content)->coords[1] *= SCALE;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[0] *= SCALE;
			((t_room*)tmp->content)->coords[1] *= SCALE;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	move_back(img, env);
	trace_point(img->env, img);
}

void	scale_down(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	move_mid(img, env);
	while (env->list)
	{
		((t_room*)env->list->content)->coords[0] /= SCALE;
		((t_room*)env->list->content)->coords[1] /= SCALE;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[0] /= SCALE;
			((t_room*)tmp->content)->coords[1] /= SCALE;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	move_back(img, env);
	trace_point(img->env, img);
}
