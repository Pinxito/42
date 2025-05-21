#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	#ifdef LOG
		ft_printf("cc");
	#endif
	return (t << 24 | r << 16 | g << 8 | b);
}


void	render_fractal(t_fractol *fract)
{
	int				x;
	int				y;
	t_fractal_vars vars;
	// Si ya existe una imagen anterior, destruirla
	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	// Crear una nueva imagen para dibujar el fractal
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	// Obtener la dirección de memoria de la nueva imagen
	fract->addr = mlx_get_data_addr(fract->img, &fract->bpp, &fract->line_length, &fract->endian);
	// Ahora puedes empezar a calcular y poner los píxeles en la nueva imagen
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// Inicializar las variables para el fractal en la posición (x, y)
			init_fractal_vars(&vars, fract, x, y);
			// Calcular el número de iteraciones del fractal
			int iterations = calculate_fractal(&vars, fract);
			// Obtener el color según el número de iteraciones
			fract->color = get_color(iterations, fract);
			// Poner el píxel en la imagen
			put_pixel_to_image(fract, x, y, fract->color);
			x++;
		}
		y++;
	}
	// Finalmente, mostrar la imagen en la ventana
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}


int	get_color(int iter, t_fractol *fract)
{
	int		r;
	int		g;
	int		b;
	double	phase;
	if (iter == fract->max_iter)
		return 0x000000; // Negro (punto dentro del conjunto)
	if (fract->psychedelic_flag == 1)
	{
		phase = fract->color_phase + iter * 0.1; // Ajustamos la fase en función de l as iteraciones
		// Modo psicodélico dinámico: color según funciones trigonométricas
		r = (int)(127.5 * (1 + sin(phase + 0)));
		g = (int)(127.5 * (1 + sin(phase + 2)));
		b = (int)(127.5 * (1 + sin(phase + 4)));
		return create_trgb(0, r, g, b);
	}
	// Modo normal: combinación simple de iteraciones
	r = (iter * 9) % 256;
	g = (iter * 2) % 256;
	b = (iter * 5) % 256;

	return create_trgb(0, r, g, b);
}



void init_fractal_vars(t_fractal_vars *vars, t_fractol *fract, int x, int y)
{
	vars->pr = fract->min_re + (x / (double)WIDTH) * (fract->max_re - fract->min_re);
	vars->pi = fract->min_im + (y / (double)HEIGHT) * (fract->max_im - fract->min_im);
	vars->old_re = vars->pr;
	vars->old_im = vars->pi;
	vars->i = 0;
}
int calculate_fractal(t_fractal_vars *vars, t_fractol *fract)
{
	while (vars->i < fract->max_iter)
	{
		if (fract->fractal_type == 0)  // Mandelbrot
		{
			vars->new_re = vars->old_re * vars->old_re - vars->old_im * vars->old_im + vars->pr;
			vars->new_im = 2 * vars->old_re * vars->old_im + vars->pi;
		}
		else if (fract->fractal_type == 2)  // Fractal del Seno
		{
			vars->new_re = sin(vars->old_re * vars->old_re - vars->old_im * vars->old_im) + vars->pr;
			vars->new_im = sin(2 * vars->old_re * vars->old_im) + vars->pi;
		}
		else// Julia
		{
			vars->new_re = vars->old_re * vars->old_re - vars->old_im * vars->old_im + fract->c_re;
			vars->new_im = 2 * vars->old_re * vars->old_im + fract->c_im;
		}
		if ((vars->new_re * vars->new_re + vars->new_im * vars->new_im) > 4)//si el punto se escapa
			return (vars->i);
		vars->old_re = vars->new_re;
		vars->old_im = vars->new_im;
		vars->i++;// Incrementar las iteraciones
	}
	return (vars->i);// Si no se escapa, devolvemos el número de iteraciones
}
