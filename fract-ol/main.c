/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:20:45 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/28 01:43:42 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc != 2 && argc != 4)
	{
		show_full_help();
		return (ft_printf("Usage: ./fractol [fractale]\n"), 0);
	}
	if (!parse_fractal_type(&fract, argc, argv))
	{
		show_full_help();
		return (ft_printf("Fractale inconnue.\n"), 1);
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
