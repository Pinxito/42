/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:08:44 by gguillen          #+#    #+#             */
/*   Updated: 2026/01/30 22:21:28 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WIDTH 800
# define HEIGHT 600
# define EPSILON 1e-6

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_mlx;
typedef struct s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3 dir; // normalizar
}					t_ray;

typedef struct s_camera
{
	t_vec3			pos;
	t_vec3			dir;
	t_vec3 forward; // eje Z cámara
	t_vec3 right;   // eje X cámara
	t_vec3 up;      // eje Y cámara
	double fov;     // campo de vision, es en grados
}					t_camera;

typedef struct s_light
{
	t_vec3			pos;
	double			intensity;
}					t_light;

typedef struct s_light_info
{
	double diffuse;   // Lambert, ∈ [0,1], dot(normal, light_dir)
	double intensity; // intensidad de la luz, ∈ [0,1]
	double ambient;   // componente ambiental opcional, ∈ [0,1]
	double specular;  // componente especular opcional, ∈ [0,1]
}					t_light_info;

typedef struct s_ambient
{
	double			ratio;
	int				color;
}					t_ambient;

typedef struct s_sphere
{
	t_vec3			center;
	double			radius;
	int				color;
}					t_sphere;

typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal; // unitario
	int				color;
}					t_plane;

typedef struct s_cylinder
{
	t_vec3			base;
	t_vec3			axis; // unitario
	double			radius;
	double			height;
	int				color;
}					t_cylinder;

typedef enum e_obj_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}					t_obj_type;

typedef struct s_object
{
	t_obj_type		type;
	void			*data;
	struct s_object	*next;
}					t_object;

typedef struct s_hit
{
	double			t;
	t_vec3			point;
	t_vec3			normal;
	int				color;
}					t_hit;

typedef struct s_scene
{
	t_mlx			mlx;
	t_camera		camera;
	t_light			light;
	t_ambient		ambient;
	t_object		*objects;
}					t_scene;

// Vectores
t_vec3				vec3_new(double x, double y, double z);
t_vec3				vec3_normalize(t_vec3 v);
t_vec3				vec3_cross(t_vec3 a, t_vec3 b);
t_vec3				vec3_sub(t_vec3 a, t_vec3 b);
t_vec3				vec3_add(t_vec3 a, t_vec3 b);
t_vec3				vec3_scale(t_vec3 v, double s);
double				vec3_dot(t_vec3 a, t_vec3 b);

// Cámara
void				init_camera_basis(t_camera *camera);

// MLX y render
int					create_trgb(int t, int r, int g, int b);
int					lambert_modele(t_hit hit, t_light light);
void				put_pixel_to_image(t_mlx *mlx_struct, int x, int y,
						int color);
int					get_pixel_color(int r, int g, int b,
						t_light_info *t_light_info);
void				prepare_render_scene(t_scene *scene);
void				render_scene(t_scene *scene);
t_ray				generate_ray(t_camera camera, int i, int j);

// Ray tracing
int					trace_ray(t_scene *scene, t_ray ray, t_hit *hit);
int					ray_sphere_intersect(t_ray ray, t_sphere sphere,
						t_hit *hit);

// Utilidades
int					close_window(t_scene *scene);
int					parse_scene(t_scene *rt, char *file);
int					clamp(int value, int min, int max);
// char    *read_line(int fd);   // definir esta función
// int     parse_line(t_scene *rt, char *line); // definir
// void    free_scene(t_scene *rt);  // definir

#endif
