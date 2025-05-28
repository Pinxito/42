/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 02:37:51 by gguillen          #+#    #+#             */
/*   Updated: 2025/05/28 02:50:22 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100
# define DOWN 65364
# define UP 65362
# define RIGHT 65363
# define LEFT 65361
# define RESET "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"

typedef struct s_fractol
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*addr;
	int						bpp;
	int						line_length;
	int						endian;
	double					min_re;
	double					max_re;
	double					min_im;
	double					max_im;
	int						max_iter;
	double					c_re;
	double					c_im;
	int						fractal_type;
	int						color;
	double					color_phase;
	int						psychedelic_flag;
	int						psychedelic_mode;
}							t_fractol;

typedef struct s_fractal_vars
{
	double					pr;
	double					pi;
	double					new_re;
	double					new_im;
	double					old_re;
	double					old_im;
	int						i;
	struct s_fractal_vars	*next;
	int						iter;
}							t_fractal_vars;

int							create_trgb(int t, int r, int g, int b);
void						render_fractal(t_fractol *fract);
int							calculate_fractal(t_fractal_vars *vars,
								t_fractol *fract);
int							get_color(int iterations, t_fractol *fract);
void						init_fractal_vars(t_fractal_vars *vars,
								t_fractol *fract, int x, int y);
int							handle_keypress(int keycode, t_fractol *fract);
int							handle_mouse(int button, int x, int y,
								t_fractol *fract);
int							handle_fractal_switch(int keycode,
								t_fractol *fract);
int							handle_psychedelic_mode(int keycode,
								t_fractol *fract);
int							handle_movement(int keycode, t_fractol *fract);
void						calculate_next(t_fractal_vars *vars,
								t_fractol *fract);

int							close_window(t_fractol *fract);
void						put_pixel_to_image(t_fractol *fract, int x, int y,
								int color);
int							main(int argc, char **argv);
void						ft_change_psychedelic_mode(t_fractol *fract);
int							ft_animate_psychedelic(t_fractol *fract);
void						init_fractol(t_fractol *fract);
int							parse_fractal_type(t_fractol *fract, int argc,
								char **argv);
double						ft_atof(const char *str);
void						show_full_help(void);
int							ft_uitoa(unsigned int nb);
int							ft_puthex(unsigned int num, const char format);
int							ft_itoa(int n);
char						*ft_convert(long int n, int is_negative);
char						*ft_convert_unsigned(unsigned int n);
void						ft_convert_hex(unsigned int num, const char format);
int							ft_countlen(long int n);
int							ft_strlen(char *str);
int							ft_putchar(char c);
int							ft_putstr(char *str);
void						ft_convert_ptr(unsigned long num);
int							ft_countptr(unsigned int n);
int							ft_putptr(void *ptr);
int							ft_printf(const char *format, ...);
int							ft_format(va_list lista, const char *format);
int							ft_countuilen(unsigned int n);
#endif
