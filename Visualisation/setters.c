/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:22:55 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 07:59:10 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "visual.h"

void		set_ants(char *line, t_env **env)
{
	t_unint	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			err_out(3, line, *env);
		++i;
	}
	if (!((*env)->ants = ft_atoi(line)))
		err_out(3, line, *env);
}

static void	set_soe(t_env **env, char c)
{
	char	*line;
	t_room	*room;

	get_next_line(0, &line);
	if (c == 's')
	{
		if ((*env)->start != NULL)
			err_out(4, line, *env);
		room = get_room(line, env, 0);
		(*env)->start = ft_lstnew(room, sizeof(*room));
		set_rooms(line, env, 0xFFFF00);
		free(room);
	}
	else if (c == 'e')
	{
		if ((*env)->end != NULL)
			err_out(4, line, *env);
		room = get_room(line, env, 0);
		(*env)->end = ft_lstnew(room, sizeof(*room));
		set_rooms(line, env, 0xFF0000);
		free(room);
	}
	(line) ? free(line) : 0;
}

void		parser_comment(char *line, t_env **env)
{
	if (line && !ft_strcmp(line, "##start"))
		set_soe(env, 's');
	else if (line && !ft_strcmp(line, "##end"))
		set_soe(env, 'e');
	else
		set_rooms(line, env, 1);
}

void		set_rooms(char *line, t_env **env, t_unint clr)
{
	t_list			*ptr;
	t_room			*room;
	static size_t	i = 2;

	if (*line == '#' && ft_strcmp(line, "##start")\
		&& ft_strcmp(line, "##end"))
		return ;
	if ((*env)->list == NULL)
	{
		room = get_room(line, env, 0);
		room->clr = clr;
		(*env)->list = ft_lstnew(room, sizeof(*room));
		free(room);
		return ;
	}
	ptr = (*env)->list;
	while (ptr->next)
		ptr = ptr->next;
	room = get_room(line, env, 0);
	room->clr = clr;
	ptr->next = ft_lstnew(room, sizeof(*room));
	free(room);
	++i;
}

void		set_links(char *line, t_env **env)
{
	char	*ln;
	char	*name;
	t_list	*lst;

	if (*line == '#')
		return ;
	if (!(*env)->start || !(*env)->end)
	{
		free(line);
		ft_error(*env);
	}
	if (!(name = (char*)malloc(sizeof(char) * ft_strlen(line))))
		err_out(0, line, *env);
	name = ft_strncpy(name, line, ft_strchr(line, '-') - line);
	name[ft_strchr(line, '-') - line] = '\0';
	ln = ft_strchr(line, '-') + 1;
	lst = (*env)->list;
	while (lst)
	{
		if (ft_strcmp(((t_room*)lst->content)->name, name) == 0)
			return (put_link(*env, (t_room**)&lst->content, ln));
		lst = lst->next;
	}
}
