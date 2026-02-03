/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:00:36 by gguillen          #+#    #+#             */
/*   Updated: 2026/01/23 18:14:17 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
void	init_camera_basis(t_camera *camera)
{
	t_vec3	up_world;

	// Forward = dirección de la cámara normalizada
	camera->forward = vec3_normalize(camera->dir);

	// Up del mundo (vector vertical “fijo”)
	up_world = vec3_new(0.0, 1.0, 0.0);

	// Right = perpendicular a forward y up_world
	camera->right = vec3_normalize(vec3_cross(camera->forward, up_world));

	// Up = perpendicular a forward y right
	camera->up = vec3_cross(camera->right, camera->forward);
}

