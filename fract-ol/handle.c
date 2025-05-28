/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 02:28:52 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/28 02:33:06 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, t_fractol *fract)
{
	double	move;

	if (keycode == 65307)
		close_window(fract);
	else if (handle_fractal_switch(keycode, fract))
		render_fractal(fract);
	else if (handle_psychedelic_mode(keycode, fract))
		render_fractal(fract);
	else if (handle_movement(keycode, fract))
		render_fractal(fract);
	else if (keycode == UP)
	{
		move = (fract->max_im - fract->min_im) * 0.05;
		fract->min_im -= move;
		fract->max_im -= move;
	}
	else if (keycode == DOWN)
	{
		move = (fract->max_im - fract->min_im) * 0.05;
		fract->min_im += move;
		fract->max_im += move;
	}
	return (0);
}

int	handle_fractal_switch(int keycode, t_fractol *fract)
{
	if (keycode == 'm' || keycode == 'M')
	{
		fract->fractal_type = 0;
		return (1);
	}
	else if (keycode == 'j' || keycode == 'J')
	{
		fract->fractal_type = 1;
		fract->c_re = -0.7;
		fract->c_im = 0.27015;
		return (1);
	}
	else if (keycode == 's' || keycode == 'S')
	{
		fract->fractal_type = 2;
		return (1);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *fract)
{
	double	zoom_factor;
	double	mouse_im;
	double	mouse_re;
	double	new_width;
	double	new_height;

	if (button == 4 || button == 5)
	{
		mouse_re = fract->min_re + (x / (double)WIDTH) * (fract->max_re
				- fract->min_re);
		mouse_im = fract->min_im + (y / (double)HEIGHT) * (fract->max_im
				- fract->min_im);
		if (button == 4)
			zoom_factor = 0.9;
		else
			zoom_factor = 1.1;
		new_height = (fract->max_im - fract->min_im) * zoom_factor;
		new_width = (fract->max_re - fract->min_re) * zoom_factor;
		fract->min_re = mouse_re - new_width * (x / (double)WIDTH);
		fract->max_re = fract->min_re + new_width;
		fract->min_im = mouse_im - new_height * (y / (double)HEIGHT);
		fract->max_im = fract->min_im + new_height;
		render_fractal(fract);
	}
	return (0);
}

int	handle_psychedelic_mode(int keycode, t_fractol *fract)
{
	if (keycode == 'p')
	{
		fract->psychedelic_flag *= -1;
		if (fract->psychedelic_flag == 1)
		{
			fract->psychedelic_mode = 1;
			ft_printf("Psychedelic mode ON\n");
		}
		else
		{
			fract->psychedelic_mode = -1;
			ft_printf("Psychedelic mode OFF\n");
		}
		return (1);
	}
	return (0);
}

int	handle_movement(int keycode, t_fractol *fract)
{
	double	move;

	if (keycode == LEFT)
	{
		move = (fract->max_re - fract->min_re) * 0.05;
		fract->min_re -= move;
		fract->max_re -= move;
	}
	else if (keycode == RIGHT)
	{
		move = (fract->max_re - fract->min_re) * 0.05;
		fract->min_re += move;
		fract->max_re += move;
	}
	else
		return (0);
	return (1);
}
