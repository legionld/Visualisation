/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mim_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:12:20 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 19:12:37 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	set_arr(int x, int y, int *max_min)
{
	if (x > max_min[1])
		max_min[1] = x;
	if (y > max_min[0])
		max_min[0] = y;
	if (x < max_min[3])
		max_min[3] = x;
	if (y < max_min[2])
		max_min[2] = y;
}
