/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:52:13 by gguillen          #+#    #+#             */
/*   Updated: 2026/06/14 12:52:14 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
** Gestionnaire de touche : ferme la fenêtre sur ESC (keycode 65307).
*/
static int	key_hook(int keycode, t_scene *scene)
{
	if (keycode == 65307)
		close_window(scene);
	return (0);
}

/*
** Initialise MinilibX, crée la fenêtre et branche les hooks.
** Appelé APRÈS validation complète du parsing.
*/
static int	init_mlx(t_scene *scene)
{
	scene->mlx.mlx = mlx_init();
	if (!scene->mlx.mlx)
		return (0);
	scene->mlx.win = mlx_new_window(scene->mlx.mlx, WIDTH, HEIGHT, "miniRT");
	if (!scene->mlx.win)
		return (0);
	scene->mlx.img = NULL;
	mlx_hook(scene->mlx.win, 17, 0, close_window, scene);
	mlx_key_hook(scene->mlx.win, key_hook, scene);
	return (1);
}

/*
** setup_scene : initialise la caméra (base orthonormée) et MinilibX.
** Appelé depuis parse_main après parse_scene réussi.
*/
int	setup_scene(t_scene *scene, t_parse_flags *flags, char *file)
{
	(void)file;
	if (!flags->has_ambient)
		parse_error("Missing ambient light (A)");
	if (!flags->has_camera)
		parse_error("Missing camera (C)");
	if (!flags->has_light)
		parse_error("Missing light (L)");
	init_camera_basis(&scene->camera);
	if (!init_mlx(scene))
	{
		free_scene_full(scene);
		parse_error("MinilibX initialization failed");
	}
	return (1);
}
