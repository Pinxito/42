/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:14:35 by gguillen          #+#    #+#             */
/*   Updated: 2026/06/10 17:27:00 by hcostoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*int parse_scene(t_scene *rt, char *file)
{
	int   fd;
	char  *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);

	while ((line = read_line(fd)))
	{
		if (!parse_line(rt, line))
		{
			free(line);
			free_scene(rt);
			close(fd);
			return (0);
		}
		free(line);
	}
	close(fd);
	return (1);
}*/
