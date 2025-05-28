/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 01:41:33 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/28 02:57:54 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_help_header(void)
{
	ft_printf(WHITE
		"╔══════════════════════════════════════════════════════╗\n");
	ft_printf("║                                                      ║\n");
	ft_printf(RED
		"║     . ⚠️ FRACTOL - AVAILABLE PARAMETERS ⚠️ .           ║\n");
	ft_printf(WHITE
		"║                                                      ║\n");
	ft_printf(CYAN
		"║  Usage: ./fractol [type] [optional parameters]       ║\n");
	ft_printf(WHITE
		"╚══════════════════════════════════════════════════════╝\n"
		RESET);
}

static void	put_help_body(void)
{
	ft_printf(CYAN
		"║                                                      ║\n");
	ft_printf("║  Available types:                                    ║\n");
	ft_printf(GREEN
		"║    ★ M/m : Mandelbrot                                ║\n");
	ft_printf(BLUE
		"║    ★ J/j : Julia (optionally: c_re c_im)             ║\n");
	ft_printf(MAGENTA
		"║    ★ S/s : Sinusoidal                                ║\n");
	ft_printf(CYAN
		"║                                                      ║\n");
	ft_printf("║  Examples:                                           ║\n");
	ft_printf(WHITE
		"║    ./fractol M                                       ║\n");
	ft_printf(
		"║    ./fractol j -0.7 0.27015                          ║\n"
		RESET);
}

static void	put_help_footer(void)
{
	ft_printf(WHITE
		"║                                                      ║\n");
	ft_printf(YELLOW
		"║  Controls:                                           ║\n");
	ft_printf(WHITE
		"║    Arrow keys : move view                            ║\n");
	ft_printf(
		"║    Mouse wheel : zoom in/out                         ║\n");
	ft_printf(
		"║    'p' : psychedelic mode                            ║\n");
	ft_printf(WHITE
		"║                                                      ║\n");
	ft_printf(GREEN
		"║  Explore the fractals and have fun!                  ║\n");
	ft_printf(WHITE
		"╚══════════════════════════════════════════════════════╝\n"
		RESET);
}

void	show_full_help(void)
{
	put_help_header();
	put_help_body();
	put_help_footer();
}
