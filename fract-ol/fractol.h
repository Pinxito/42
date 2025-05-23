#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdarg.h>
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

// Definir los eventos del teclado
#define KEY_ESC 53
#define KEY_J 38  // Tecla J para Julia
#define KEY_M 46  // Tecla M para Mandelbrot
#define KEY_P 112         // Tecla P para activar/desactivar el modo psicodélico
#define KEY_C 99          // Tecla C para cambiar la paleta de colores

typedef struct s_fractol {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    
    // Parámetros comunes
    double  min_re;
    double  max_re;
    double  min_im;
    double  max_im;
    int     max_iter;

    // Parámetros para Julia
    double  c_re;
    double  c_im;
    
    // Parámetro adicional para identificar qué fractal se está generando
    int     fractal_type;  // 0 = Mandelbrot, 1 = Julia, 2 = otros fractales
    //extras
    int color;                // Color base del fractal
    double color_phase;//variable que cambia con el tiempo
    int psychedelic_flag;      // Modo psicodélico (1 = activado, 0 = desactivado)
    int psychedelic_mode;      // Cambia en los diferentes modos psicodelicos
}               t_fractol;

//lista de variables
typedef struct s_fractal_vars
{
    double pr;
    double pi;
    double new_re;
    double new_im;
    double old_re;
    double old_im;
    int i;
    struct s_fractal_vars *next;
    int iter;
} t_fractal_vars;

//utils
int     create_trgb(int t, int r, int g, int b);
void render_fractal(t_fractol *fract);
int calculate_fractal(t_fractal_vars *vars, t_fractol *fract);
int get_color(int iterations, t_fractol *fract);
void init_fractal_vars(t_fractal_vars *vars, t_fractol *fract, int x, int y);
int handle_keypress(int keycode, t_fractol *fract);
int handle_mouse(int button, int x, int y, t_fractol *fract);

int close_window(t_fractol *fract);
void put_pixel_to_image(t_fractol *fract, int x, int y, int color);
int main();
//extras
void ft_change_psychedelic_mode(t_fractol *fract);
int ft_animate_psychedelic(t_fractol *fract);
void init_fractol(t_fractol *fract);
int parse_fractal_type(t_fractol *fract, char *arg);


//printf
int			ft_uitoa(unsigned int nb);
int			ft_puthex(unsigned int num, const char format);
int			ft_itoa(int n);
char		*ft_convert(long int n, int is_negative);
char		*ft_convert_unsigned(unsigned int n);
void		ft_convert_hex(unsigned int num, const char format);
int			ft_countlen(long int n);
int			ft_strlen(char *str);
int			ft_putchar(char c);
int			ft_putstr(char *str);
void		ft_convert_ptr(unsigned long num);
int			ft_countptr(unsigned int n);
int			ft_putptr(void *ptr);
int	        ft_printf(const char *format, ...);
int	        ft_format(va_list lista, const char *format);
int	        ft_countuilen(unsigned int n);
#endif
