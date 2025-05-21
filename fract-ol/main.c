#include "fractol.h"

/*int close_window(void *mlx)
{
    free(mlx);
    exit(0);
    return (0);
}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (!mlx)
        return (1);
    
    win = mlx_new_window(mlx, 800, 600, "fract-ol");
    if (!win)
    {
        free(mlx);
        return (1);
    }

    mlx_clear_window(mlx, win);
    
    // Dibujar un punto verde
    mlx_pixel_put(mlx, win, 400, 300, 0x00FF00); 

    // Mostrar texto en la ventana
    mlx_string_put(mlx, win, 100, 100, 0xFF0000, "¡Hola, fractal!");

    // Manejador para cerrar la ventana
    mlx_hook(win, 17, 0L, close_window, mlx);
    
    // Iniciar el bucle de eventos
    mlx_loop(mlx);

    return (0);
}*/
/*int main()
{
    t_fractol fract;

    fract.mlx = mlx_init();
    fract.win = mlx_new_window(fract.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
    fract.min_re = -2.0;
    fract.max_re = 1.0;
    fract.min_im = -1.2;
    fract.max_im = 1.2;
    render_fractal(&fract);
    mlx_loop(fract.mlx);
    return (0);
}*/


#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractol fract;

    if (argc != 2)
    {
        ft_printf("Usage: ./fractol [fractale]\n");
        return (1);
    }

    // Inicializar valores predeterminados
    fract.mlx = mlx_init();
    fract.win = mlx_new_window(fract.mlx, WIDTH, HEIGHT, "Fract'ol");
    fract.psychedelic_flag = -1;  // Empieza desactivado
    fract.color = 0xFFFFFF;  // Color inicial (blanco)
    fract.img = mlx_new_image(fract.mlx, WIDTH, HEIGHT);
    fract.addr = mlx_get_data_addr(fract.img, &fract.bpp, &fract.line_length, &fract.endian);
    fract.psychedelic_mode = -1;
    fract.color_phase = 0.0;

    fract.fractal_type = 0;  // 0 para Mandelbrot por defecto
    fract.max_iter = MAX_ITER;
    fract.min_re = -2.0;
    fract.max_re = 2.0;
    fract.min_im = -2.0;
    fract.max_im = 2.0;

    // Usar el primer argumento para determinar el tipo de fractal
    if (argv[1][0] == 'm' || argv[1][0] == 'M')  // Para Mandelbrot
    {
        fract.fractal_type = 0;  // Mandelbrot
    }
    else if (argv[1][0] == 'j' || argv[1][0] == 'J')  // Para Julia
    {
        fract.fractal_type = 1;// Julia
    }
     else if (argv[1][0] == 's' || argv[1][0] == 'S')  // Para Seno
    {
        fract.fractal_type = 2;  // Seno
    }
    else
    {
        ft_printf("Fractale inconnue.\n");
        return (1);
    }

    // Configuración de Julia set si se usa el fractal Julia
    if (fract.fractal_type == 1)
    {
        fract.c_re = -0.7;
        fract.c_im = 0.27015;
    }
    // Llamar a la función para renderizar el fractal
    render_fractal(&fract);
    // Configurar eventos: presionar teclas y cierre de la ventana
    mlx_key_hook(fract.win, handle_keypress, &fract);  // Manejo de teclas
    mlx_mouse_hook(fract.win, handle_mouse, &fract); //zoom
    mlx_hook(fract.win, 17, 0, close_window, &fract);   // Cerrar la ventana (clic en la "X")
    // Empezar el bucle de eventos
    mlx_loop_hook(fract.mlx, ft_animate_psychedelic, &fract);  // Llamar a la animación en cada iteración
    mlx_loop(fract.mlx);  // Iniciar el bucle de eventos

    return (0);
}
