#include "fractol.h"
#include <stdio.h>  // Para debug con printf


void ft_change_psychedelic_mode(t_fractol *fract)
{
    // Cambiar entre las 5 paletas disponibles
    fract->psychedelic_mode = (fract->psychedelic_mode + 1) % 5; // Cambia entre 5 paletas
    render_fractal(fract);  // Redibujar el fractal con la nueva paleta
}


int ft_animate_psychedelic(t_fractol *fract)
{
    static int frame = 0;  // Variable para controlar la velocidad de la animación

    // Verifica si el modo psicodélico está activado
    if (fract->psychedelic_flag == 0)
    {
        return 0; // No hacer nada si el modo psicodélico está desactivado
    }
    // Controla la velocidad de cambio (cada 10 frames cambia el color)
    if (frame % 10 == 0)  
    {
        // Cambia la fase del color para generar un cambio en el color
        fract->color_phase += 0.1; 
        // Limitar el valor para evitar un valor muy grande
        if (fract->color_phase > 1000.0)
        {
            fract->color_phase = 0.0; // Resetea la fase
        }
        render_fractal(fract);  // Redibuja el fractal con el nuevo color
    }
    frame++;  // Incrementa el contador de frames
    return 0;
}

