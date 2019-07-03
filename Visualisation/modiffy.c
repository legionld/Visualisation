/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modiffy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 08:02:24 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 08:02:48 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	scale_h_up(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	move_mid(img, env);
	while (env->list)
	{
		((t_room*)env->list->content)->coords[0] *= SCALE;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[0] *= SCALE;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	move_back(img, env);
	trace_point(img->env, img);
}

void	scale_w_up(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	move_mid(img, env);
	while (env->list)
	{
		((t_room*)env->list->content)->coords[1] *= SCALE;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[1] *= SCALE;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	move_back(img, env);
	trace_point(img->env, img);
}

void	scale_h_down(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	move_mid(img, env);
	while (env->list)
	{
		((t_room*)env->list->content)->coords[0] /= SCALE;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[0] /= SCALE;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	move_back(img, env);
	trace_point(img->env, img);
}

void	scale_w_down(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	move_mid(img, env);
	while (env->list)
	{
		((t_room*)env->list->content)->coords[1] /= SCALE;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[1] /= SCALE;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	move_back(img, env);
	trace_point(img->env, img);
}

void	scale_d(t_mlx *img, t_env *env, float scale)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	move_mid(img, env);
	while (env->list)
	{
		((t_room*)env->list->content)->coords[0] *= scale;
		((t_room*)env->list->content)->coords[1] *= scale;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[0] *= scale;
			((t_room*)tmp->content)->coords[1] *= scale;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	move_back(img, env);
	trace_point(img->env, img);
}
