/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:54:37 by lgigi             #+#    #+#             */
/*   Updated: 2019/06/29 16:18:45 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_room				*get_room(char *line, t_env **env, short comm)
{
	t_room			*room;
	static t_unint	index = 0;
	char			**split;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		err_out(0, line, *env);
	comm = 0;
	split = ft_strsplit(line, ' ');
	room->name = ft_strdup(split[0]);
	room->index = index;
	room->coords[0] = ft_atoi(split[1]);
	room->coords[1] = ft_atoi(split[2]);
	room->links = NULL;
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split);
	++index;
	return (room);
}
