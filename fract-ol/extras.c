/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papprikka <papprikka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:09:34 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/24 17:49:48 by papprikka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_change_psychedelic_mode(t_fractol *fract)
{
	fract->psychedelic_mode = (fract->psychedelic_mode + 1) % 5;
	render_fractal(fract);
}

void	init_fractol(t_fractol *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "Fract'ol");
	fract->psychedelic_flag = -1;
	fract->psychedelic_mode = -1;
	fract->color_phase = 0.0;
	fract->color = 0xFFFFFF;
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->addr = mlx_get_data_addr(fract->img, &fract->bpp,
			&fract->line_length, &fract->endian);
	fract->max_iter = MAX_ITER;
	fract->min_re = -2.0;
	fract->max_re = 2.0;
	fract->min_im = -2.0;
	fract->max_im = 2.0;
}

int	parse_fractal_type(t_fractol *fract, int argc, char **argv)
{
	if (argc >= 2 && argv[1] && argv[1][0] && argv[1][1] == '\0')
	{
		if (argv[1][0] == 'm' || argv[1][0] == 'M')
			fract->fractal_type = 0;
		else if (argv[1][0] == 'j' || argv[1][0] == 'J')
		{
			fract->fractal_type = 1;
			fract->c_re = -0.7;
			fract->c_im = 0.27015;
			if (argc == 4)
			{
				fract->c_re = ft_atof(argv[2]);
				fract->c_im = ft_atof(argv[3]);
			}
		}
		else if (argv[1][0] == 's' || argv[1][0] == 'S')
			fract->fractal_type = 2;
		else
			return (0);
		return (1);
	}
	return (ft_printf("Usage: ./fractol [M/m/J/j/S/s]\n"), 0);
}

void	init_fractal_vars(t_fractal_vars *vars, t_fractol *fract, int x, int y)
{
	vars->pr = fract->min_re + (x / (double)WIDTH) * (fract->max_re - fract->min_re);
	vars->pi = fract->min_im + (y / (double)HEIGHT) * (fract->max_im - fract->min_im);
	vars->old_re = vars->pr;
	vars->old_im = vars->pi;
	vars->i = 0;
}
