/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:48:16 by gguillen          #+#    #+#             */
/*   Updated: 2026/06/14 12:48:17 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
** Libère la liste chaînée d'objets de la scène.
** Libère aussi le data (sp/pl/cy) de chaque nœud.
*/
void	free_scene_objects(t_scene *scene)
{
	t_object	*cur;
	t_object	*next;

	cur = scene->objects;
	while (cur)
	{
		next = cur->next;
		if (cur->data)
			free(cur->data);
		free(cur);
		cur = next;
	}
	scene->objects = NULL;
}

/*
** Libère toutes les ressources allouées dans la scène.
** À appeler en cas d'erreur après un parsing partiel.
*/
void	free_scene_full(t_scene *scene)
{
	free_scene_objects(scene);
}
