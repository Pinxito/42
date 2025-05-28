/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:48:45 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/28 02:19:49 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fractol *fract)
{
	int				x;
	int				y;
	int				iterations;
	t_fractal_vars	vars;

	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->addr = mlx_get_data_addr(fract->img, &fract->bpp,
			&fract->line_length, &fract->endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			init_fractal_vars(&vars, fract, x, y);
			iterations = calculate_fractal(&vars, fract);
			fract->color = get_color(iterations, fract);
			put_pixel_to_image(fract, x, y, fract->color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}

int	get_color(int iter, t_fractol *fract)
{
	int		r;
	int		g;
	int		b;
	double	phase;

	if (iter == fract->max_iter)
		return (0x000000);
	if (fract->psychedelic_flag == 1)
	{
		phase = fract->color_phase + iter * 0.1;
		r = (int)(127.5 * (1 + sin(phase + 0)));
		g = (int)(127.5 * (1 + sin(phase + 2)));
		b = (int)(127.5 * (1 + sin(phase + 4)));
		return (create_trgb(0, r, g, b));
	}
	r = (iter * 9) % 256;
	g = (iter * 2) % 256;
	b = (iter * 5) % 256;
	return (create_trgb(0, r, g, b));
}

void	calculate_next(t_fractal_vars *vars, t_fractol *fract)
{
	if (fract->fractal_type == 0)
	{
		vars->new_re = vars->old_re * vars->old_re - vars->old_im * vars->old_im
			+ vars->pr;
		vars->new_im = 2 * vars->old_re * vars->old_im + vars->pi;
	}
	else if (fract->fractal_type == 2)
	{
		vars->new_re = sin(vars->old_re * vars->old_re - vars->old_im
				* vars->old_im) + vars->pr;
		vars->new_im = sin(2 * vars->old_re * vars->old_im) + vars->pi;
	}
	else
	{
		vars->new_re = vars->old_re * vars->old_re - vars->old_im * vars->old_im
			+ fract->c_re;
		vars->new_im = 2 * vars->old_re * vars->old_im + fract->c_im;
	}
}

int	calculate_fractal(t_fractal_vars *vars, t_fractol *fract)
{
	while (vars->i < fract->max_iter)
	{
		calculate_next(vars, fract);
		if ((vars->new_re * vars->new_re + vars->new_im * vars->new_im) > 4)
			return (vars->i);
		vars->old_re = vars->new_re;
		vars->old_im = vars->new_im;
		vars->i++;
	}
	return (vars->i);
}

int	ft_animate_psychedelic(t_fractol *fract)
{
	static int	frame;

	frame = 0;
	if (fract->psychedelic_flag == 0)
		return (0);
	if (frame % 10 == 0)
	{
		fract->color_phase += 0.1;
		if (fract->color_phase > 1000.0)
			fract->color_phase = 0.0;
		render_fractal(fract);
	}
	frame++;
	return (0);
}
