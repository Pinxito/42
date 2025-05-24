/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papprikka <papprikka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:20:45 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/23 23:25:54 by papprikka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc != 2)
	{
		show_full_help(&fract);
		return (ft_printf("Usage: ./fractol [fractale]\n"),1);
	}
	if (!parse_fractal_type(&fract, argc, argv))
	{
		show_full_help(&fract);
		return (ft_printf("Fractale inconnue.\n"),1);
	}
	init_fractol(&fract);
	render_fractal(&fract);
	mlx_key_hook(fract.win, handle_keypress, &fract);
	mlx_mouse_hook(fract.win, handle_mouse, &fract);
	mlx_hook(fract.win, 17, 0, close_window, &fract);
	mlx_loop_hook(fract.mlx, ft_animate_psychedelic, &fract);
	mlx_loop(fract.mlx);
	return (0);
}
