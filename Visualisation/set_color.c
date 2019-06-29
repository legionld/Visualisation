/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:48:39 by jschille          #+#    #+#             */
/*   Updated: 2019/06/29 16:02:28 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	change_color(t_room *room, t_ant *ant)
{
	if (ant->room->clr != 0xFFFF00 || ant->room->clr != 0xFF0000)
		ant->room->clr = 0xFFFFFF;
	ant->room = room;
	ant->room->clr = 0xFF00;
}

static void	set_color(t_env *env, char **path)
{
	t_unint	ant;
	t_unint	i;
	t_list	*lants;
	t_list	*lst;
	char	*name;

	i = 0;
	while (path[i] != NULL)
	{
		ant = ft_atoi(path[i] + 1);
		lants = env->lants;
		while (((t_ant*)lants->content)->name != ant)
			lants = lants->next;
		lst = env->list;
		name = ft_strdup((char*)(ft_strchr(path[i], '-') + 1));
		while (lst)
		{
			if (ft_strcmp(((t_room*)lst->content)->name, name) == 0)
				change_color(lst->content, lants->content);
			lst = lst->next;
		}
		++i;
	}
}

void	next_step(t_mlx *img, t_env *env)
{
	char	**split;
	int		i;

	get_next_line(0, &(img->line));
	if (!img->line || !*img->line)
		err_out(2, img->line, env);
	split = ft_strsplit(img->line, ' ');
	i = 0;
	set_color(env, split);
	trace_point(img->env, img);
}