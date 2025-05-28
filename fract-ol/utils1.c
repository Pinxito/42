/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:10:41 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/28 13:55:09 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *fract)
{
	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	exit(0);
}

void	put_pixel_to_image(t_fractol *fract, int x, int y, int iterations)
{
	char	*dst;
	int		color;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	if (iterations == fract->max_iter)
		color = 0x000000;
	else
		color = get_color(iterations, fract);
	dst = fract->addr + (y * fract->line_length + x * (fract->bpp / 8));
	*(unsigned int *)dst = color;
}

int	validate_julia_range(t_fractol *fract, int argc)
{
	if (argc == 4)
	{
		if (fract->c_re < -2.0 || fract->c_re > 2.0
			|| fract->c_im < -2.0 || fract->c_im > 2.0)
		{
			show_full_help();
			ft_printf("❌ Values out of range.\n");
			ft_printf(" Please use numbers between -2.0 and 2.0\n");
			return (0);
		}
	}
	return (1);
}
