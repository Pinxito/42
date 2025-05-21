#include "fractol.h"
int handle_keypress(int keycode, t_fractol *fract)
{
    if (keycode == 65307)  // Tecla ESC
        close_window(fract);
    else if (keycode == 'm' || keycode == 'M') // Cambiar a Mandelbrot
    {
        fract->fractal_type = 0;
        render_fractal(fract);  // Redibujar el fractal
    }
    else if (keycode == 'j' || keycode == 'J') // Cambiar a Julia
    {
        fract->fractal_type = 1;
        fract->c_re = -0.7;
        fract->c_im = 0.27015;
        render_fractal(fract);  // Redibujar el fractal
    }
    else if (keycode == 's' || keycode == 'S') // Cambiar a Seno
    {
        fract->fractal_type = 2;
        render_fractal(fract);  // Redibujar el fractal
    }
    else if (keycode == 'p')  // Activar/desactivar el modo psicodélico
{
    fract->psychedelic_flag *= -1;  // Alternar entre activado/desactivado
    if (fract->psychedelic_flag == 1)
    {
        fract->psychedelic_mode = 1;  // Activar el modo psicodélico
        ft_printf("Psychedelic mode ON\n");
    }
    else
    {
        fract->psychedelic_mode = -1;  // Desactivar el modo psicodélico
        ft_printf("Psychedelic mode OFF\n");
    }
    render_fractal(fract);  // Redibujar el fractal después de cambiar el modo
}

    else if (keycode == 'c')  // Cambiar la paleta dentro del modo psicodélico
    {
        ft_change_psychedelic_mode(fract);
        render_fractal(fract);
    }
    else if (keycode == 65361) // Flecha izquierda
{
    double move = (fract->max_re - fract->min_re) * 0.05;
    fract->min_re -= move;
    fract->max_re -= move;
}
else if (keycode == 65363) // Flecha derecha
{
    double move = (fract->max_re - fract->min_re) * 0.05;
    fract->min_re += move;
    fract->max_re += move;
}
else if (keycode == 65362) // Flecha arriba
{
    double move = (fract->max_im - fract->min_im) * 0.05;
    fract->min_im -= move;
    fract->max_im -= move;
}
else if (keycode == 65364) // Flecha abajo
{
    double move = (fract->max_im - fract->min_im) * 0.05;
    fract->min_im += move;
    fract->max_im += move;
}
render_fractal(fract);


    return 0;
}

int handle_mouse(int button, int x, int y, t_fractol *fract)
{
    double zoom_factor;

    if (button == 4 || button == 5) // 4 = scroll up, 5 = scroll down (Linux X11)
    {
        double mouse_re = fract->min_re + (x / (double)WIDTH) * (fract->max_re - fract->min_re);
        double mouse_im = fract->min_im + (y / (double)HEIGHT) * (fract->max_im - fract->min_im);

        if (button == 4) // Scroll up = Zoom in
            zoom_factor = 0.9;
        else            // Scroll down = Zoom out
            zoom_factor = 1.1;

        double new_width = (fract->max_re - fract->min_re) * zoom_factor;
        double new_height = (fract->max_im - fract->min_im) * zoom_factor;

        fract->min_re = mouse_re - new_width * (x / (double)WIDTH);
        fract->max_re = fract->min_re + new_width;
        fract->min_im = mouse_im - new_height * (y / (double)HEIGHT);
        fract->max_im = fract->min_im + new_height;

        render_fractal(fract); // Redibujar con zoom
    }
    return 0;
}


// Función para manejar el evento de cierre de la ventana (clic en la "X")
int close_window(t_fractol *fract)
{
    if (fract->img)
        mlx_destroy_image(fract->mlx, fract->img);
    if (fract->win)
        mlx_destroy_window(fract->mlx, fract->win);
    exit(0);
}
void put_pixel_to_image(t_fractol *fract, int x, int y, int iterations)
{
    char *dst;
    int color;

    // Verifica que el píxel esté dentro de los límites de la ventana
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    // Si iterations == max_iter, el punto está dentro (negro), si no, usa la paleta
    if (iterations == fract->max_iter)
        color = 0x000000;  // Negro para puntos dentro del fractal
    else
        color = get_color(iterations, fract);  
    dst = fract->addr + (y * fract->line_length + x * (fract->bpp / 8));
    *(unsigned int *)dst = color;
}

