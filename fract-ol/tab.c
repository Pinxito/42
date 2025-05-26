
#include "fractol.h"

#define RESET      "\033[0m"
#define RED        "\033[1;31m"
#define GREEN      "\033[1;32m"
#define YELLOW     "\033[1;33m"
#define BLUE       "\033[1;34m"
#define MAGENTA    "\033[1;35m"
#define CYAN       "\033[1;36m"
#define WHITE      "\033[1;37m"

static void	put_help_header(void)
{
	ft_printf(WHITE"╔══════════════════════════════════════════════════════╗\n");
	ft_printf("║                                                      ║\n");
	ft_printf(RED"║     . ⚠️ FRACTOL - AVAILABLE PARAMETERS ⚠️ .         ║\n");
	ft_printf(WHITE"║                                                      ║\n");
	ft_printf(CYAN"║  Usage: ./fractol [type] [optional parameters]       ║\n");
	ft_printf(WHITE"╚══════════════════════════════════════════════════════╝\n\n"RESET);
}

static void	put_help_body(void)
{
	ft_printf(CYAN"║                                                      ║\n");
	ft_printf("║  Available types:                                    ║\n");
	ft_printf(GREEN "║    ★ M/m : Mandelbrot                                ║\n");
	ft_printf(BLUE  "║    ★ J/j : Julia (optionally: c_re c_im)             ║\n");
	ft_printf(MAGENTA"║    ★ S/s : Sinusoidal                                ║\n");
	ft_printf(CYAN"║                                                      ║\n");
	ft_printf("║  Examples:                                           ║\n");
	ft_printf(WHITE "║    ./fractol M                                       ║\n");
	ft_printf("║    ./fractol j -0.7 0.27015                          ║\n"RESET);
}

static void	put_help_footer(void)
{
	ft_printf(WHITE"║                                                      ║\n");
	ft_printf(YELLOW"║  Controls:                                           ║\n");
	ft_printf(WHITE "║    Arrow keys : move view                            ║\n");
	ft_printf("║    Mouse wheel : zoom in/out                         ║\n");
	ft_printf("║    'p' : psychedelic mode                            ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf(GREEN"║  Explore the fractals and have fun!                  ║\n");
	ft_printf(WHITE"╚══════════════════════════════════════════════════════╝\n"RESET);
}



void	show_full_help(void)
{
	
	put_help_header();
	put_help_body();
	put_help_footer();
	
}
