/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveble.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:39:29 by jschille          #+#    #+#             */
/*   Updated: 2019/06/29 21:18:22 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	move_left(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	while (env->list)
	{
		((t_room*)env->list->content)->coords[1] -= 2;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[1] -= 2;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	img->half_x -= 2;
	trace_point(img->env, img);
}

void	move_right(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	while (env->list)
	{
		((t_room*)env->list->content)->coords[1] += 2;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[1] += 2;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	img->half_x += 2;
	trace_point(img->env, img);
}

void	move_up(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	while (env->list)
	{
		((t_room*)env->list->content)->coords[0] -= 2;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[0] -= 2;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	img->half_y -= 2;
	trace_point(img->env, img);
}

void	move_down(t_mlx *img, t_env *env)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	while (env->list)
	{
		((t_room*)env->list->content)->coords[0] += 2;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[0] += 2;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	img->half_y += 2;
	trace_point(img->env, img);
}

void	move_img(t_mlx *img, t_env *env, int x, int y)
{
	t_list	*lst;
	t_list	*tmp;

	lst = img->env->list;
	while (env->list)
	{
		((t_room*)env->list->content)->coords[1] += x;
		((t_room*)env->list->content)->coords[0] += y;
		tmp = ((t_room*)env->list->content)->links;
		while (tmp)
		{
			((t_room*)tmp->content)->coords[1] += x;
			((t_room*)tmp->content)->coords[0] += y;
			tmp = tmp->next;
		}
		env->list = env->list->next;
	}
	env->list = lst;
	img->half_x += x;
	img->half_x += y;
	trace_point(img->env, img);
}
