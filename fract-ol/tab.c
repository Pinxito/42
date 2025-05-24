#include <stdlib.h>
#include "fractol.h"
static void	put_help_header(t_fractol *fract)
{
	int y = 20;

	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"╔══════════════════════════════════════════════════════╗");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"║                                                      ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFF0000,
		"║     . ⚠️ FRACTOL - AVAILABLE PARAMETERS ⚠️ .      ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"║                                                      ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0x00FFFF,
		"║  Usage: ./fractol [type] [optional parameters]        ║");
}
static void	put_help_body(t_fractol *fract)
{
	int y = 140;

	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0x00FFFF,
		"║                                                      ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0x00FFFF,
		"║  Available types:                                     ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0x00FF00,
		"║    ★ M/m : Mandelbrot                                 ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0x0000FF,
		"║    ★ J/j : Julia (optionally: c_re c_im)              ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFF00FF,
		"║    ★ S/s : Sinusoidal                                 ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"║                                                      ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0x00FFFF,
		"║  Examples:                                             ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"║    ./fractol M                                        ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"║    ./fractol j -0.7 0.27015                            ║");
}
static void	put_help_footer(t_fractol *fract)
{
	int y = 300;

	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"║                                                      ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFF00,
		"║  Controls:                                            ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"║    Arrow keys : move view                             ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"║    Mouse wheel : zoom in/out                          ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"║    'p' : psychedelic mode                             ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"║                                                      ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0x00FF00,
		"║  Explore the fractals and have fun!                  ║");
	mlx_string_put(fract->mlx, fract->win, 20, y += 20, 0xFFFFFF,
		"╚══════════════════════════════════════════════════════╝");
}

static void	init_help_window(t_fractol *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		exit(1);

	fract->win = mlx_new_window(fract->mlx, 600, 600, "Fractol - Help");
	if (!fract->win)
		exit(1);
}
void	show_full_help(t_fractol *fract)
{
	
	init_help_window(fract);
	init_fractol(fract);
	put_help_header(fract);
	put_help_body(fract);
	put_help_footer(fract);
	mlx_key_hook(fract->win, handle_keypress, fract);
	mlx_mouse_hook(fract->win, handle_mouse, fract);
	mlx_hook(fract->win, 17, 0, close_window, fract);
	mlx_loop(fract->mlx);
}
