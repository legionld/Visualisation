/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:50:45 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 07:56:05 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include <fcntl.h>

void			err_out(int e, char *line, t_env *env)
{
	(line) ? free(line) : 0;
	if (e == 0)
		write(2, "Error! Don't have memory\n", 25);
	if (e == 1)
		write(2, "Error! Don't open file\n", 23);
	if (e == 2)
		write(2, "Error! Can not open file\n", 25);
	if (e == 3)
		write(2, "Error! Numbers of ants have invalid symbol\n", 43);
	if (e == 4)
		write(2, "Error! Dublicate Start/End\n", 27);
	if (e == 5)
		write(2, "Error! Bad symbol\n", 18);
	if (e == -1)
		exit(clean_env(env));
	return (ft_error(env));
}

static void		check_line(char *line, t_env **env)
{
	static t_unint	count = 0;

	if (line && count == 0 && line[0] != '#' && (count = 1))
		set_ants(line, env);
	else if (line && line[0] == '#')
		parser_comment(line, env);
	else if (line && ft_strchr(line, '-'))
		set_links(line, env);
	else if (line && count == 1)
		set_rooms(line, env, 0xFFFFFF);
}

static void		read_data(int fd, t_env **env)
{
	char	*line;
	int		rd;

	while ((rd = get_next_line(fd, &line)) > 0)
	{
		if (!*line)
			break ;
		if (!line || !*line)
		{
			(line) ? free(line) : 0;
			ft_error(*env);
		}
		check_line(line, env);
		free(line);
	}
	(line) ? free(line) : 0;
	if (rd < 0)
		ft_error(*env);
}

t_env			*env_init(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		err_out(0, 0, 0);
	env->start = NULL;
	env->end = NULL;
	env->list = NULL;
	env->lants = NULL;
	return (env);
}

t_env			*parser(void)
{
	t_env	*env;

	env = env_init();
	read_data(0, &env);
	return (env);
}
