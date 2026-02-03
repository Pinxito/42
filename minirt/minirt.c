/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:08:40 by gguillen          #+#    #+#             */
/*   Updated: 2026/02/02 15:15:41 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*int	main(void)
{
	t_scene	scene;

	// Inicializar MLX
	scene.mlx.mlx = mlx_init();
	scene.mlx.win = mlx_new_window(scene.mlx.mlx, WIDTH, HEIGHT, "miniRT");


	// Configurar cámara
	scene.camera.pos = vec3_new(0, 0, 0);
	scene.camera.dir = vec3_new(0, 0, -1);
	scene.camera.fov = 90;
	init_camera_basis(&scene.camera);

	//luz
	scene.light.pos = vec3_new(5, 5, 0);  // posición de la luz
	scene.light.intensity = 1.0;          // intensidad máxima

	//esfera
	t_sphere *sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (1);
	sphere->center = vec3_new(0, 0, -5);  
	sphere->radius = 1.0;
	sphere->color = create_trgb(0, 255, 0, 0); // rojo

	t_object *obj = malloc(sizeof(t_object));
	if (!obj)
		return (1);
	obj->type = OBJ_SPHERE;
	obj->data = sphere;
	obj->next = NULL;
	scene.objects = obj;

	prepare_render_scene(&scene);
	render_scene(&scene);

	mlx_loop(scene.mlx.mlx);

	return (0);
}*/
int	main(void)
{
	t_scene		scene;
	t_sphere	*sphere1;
	t_sphere	*sphere2;
	t_sphere	*sphere3;
	t_object	*obj1;
	t_object	*obj2;
	t_object	*obj3;

	// Inicializar MLX
	scene.mlx.mlx = mlx_init();
	scene.mlx.win = mlx_new_window(scene.mlx.mlx, WIDTH, HEIGHT, "miniRT");

	// Configurar cámara
	scene.camera.pos = vec3_new(0, 0, 0);
	scene.camera.dir = vec3_new(0, 0, -1);
	scene.camera.fov = 90;
	init_camera_basis(&scene.camera);

	// Luz
	scene.light.pos = vec3_new(5, 5, 0);
	scene.light.intensity = 1.0;

	/* -------- Esfera 1 -------- */
	sphere1 = malloc(sizeof(t_sphere));
	if (!sphere1)
		return (1);
	sphere1->center = vec3_new(-1, 0, -5);
	sphere1->radius = 2.0;
	sphere1->color = create_trgb(0, 255, 0, 0); // rojo

	obj1 = malloc(sizeof(t_object));
	if (!obj1)
		return (1);
	obj1->type = OBJ_SPHERE;
	obj1->data = sphere1;

	/* -------- Esfera 2 -------- */
	sphere2 = malloc(sizeof(t_sphere));
	if (!sphere2)
		return (1);
	sphere2->center = vec3_new(1, 0, -5);
	sphere2->radius = 2.0;
	sphere2->color = create_trgb(0, 0, 255, 0); // verde

	obj2 = malloc(sizeof(t_object));
	if (!obj2)
		return (1);
	obj2->type = OBJ_SPHERE;
	obj2->data = sphere2;

	/* -------- Esfera 3 -------- */
	sphere3 = malloc(sizeof(t_sphere));
	if (!sphere3)
		return (1);
	sphere3->center = vec3_new(0, 0, -8);
	sphere3->radius = 3.0;
	sphere3->color = create_trgb(0, 0, 0, 255); // azul

	obj3 = malloc(sizeof(t_object));
	if (!obj3)
		return (1);
	obj3->type = OBJ_SPHERE;
	obj3->data = sphere3;

	/* -------- Enlazar objetos -------- */
	obj1->next = obj2;
	obj2->next = obj3;
	obj3->next = NULL;
	scene.objects = obj1;

	prepare_render_scene(&scene);
	render_scene(&scene);

	mlx_loop(scene.mlx.mlx);
	return (0);
}



