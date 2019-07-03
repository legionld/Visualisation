/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 07:04:21 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 07:41:11 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		clean_env(t_env *env)
{
	while (env->list)
	{
		free(((t_room*)env->list->content)->name);
		free(env->list->content);
		env->list = env->list->next;
	}
	free(env->start->content);
	free(env->end->content);
	while (env->lants)
	{
		(env->lants->content) ? free(env->lants->content) : 0;
		env->lants = env->lants->next;
	}
	return (0);
}

int		clean(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->mlx_ptr);
	mlx->line ? free(mlx->line) : 0;
	return (0);
}
