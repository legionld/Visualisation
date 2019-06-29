/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:38:40 by jschille          #+#    #+#             */
/*   Updated: 2019/06/29 14:34:14 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_error(t_env *e)
{
	if (e)
		free(e);
	write(2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}

void	put_link(t_env *env, t_room **room, char *name)
{
	t_list	*lst;

	lst = env->list;
	while (lst)
	{
		if (ft_strcmp(((t_room*)lst->content)->name, name) == 0)
		{
			ft_lstadd(&(*room)->links, ft_lstnew(lst->content, sizeof(**room)));
			return ;
		}
		lst = lst->next;
	}
}

t_mlx	*set_data(t_env *env)
{
	t_mlx	*mlx;
	int		i;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		err_out(0, NULL, env);
	mlx->bpp = 4;
	mlx->size_line = WIDTH;
	mlx->alpha = 1;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HIGHT, "map");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HIGHT);
	mlx->img_data = (unsigned int*)mlx_get_data_addr(mlx->img_ptr,
					&(mlx->bpp), &(mlx->size_line), &(mlx->alpha));
	mlx->env = env;
	i = -1;
	while (++i < 4)
		mlx->extrem[i] = 0;
	return (mlx);
}

int		main(void)
{
	t_env	*env;

	env = parser();
	set_lants(&env);
	display_out(env);
	exit(0);
}
