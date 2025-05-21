#include "fractol.h"

int julia_iter(double zr, double zi, double c_re, double c_im)
{
    double tmp;
    int iter = 0;

    while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
    {
        tmp = zr * zr - zi * zi + c_re;
        zi = 2.0 * zr * zi + c_im;
        zr = tmp;
        iter++;
    }
    return (iter);
}

void julia(t_fractol *fract)
{
    int x, y, iter;
    double cr, ci;
    int color;

    y = 0;
    while (y < HEIGHT)
    {
        ci = fract->min_im + (y / (double)HEIGHT) * (fract->max_im - fract->min_im);
        x = 0;
        while (x < WIDTH)
        {
            cr = fract->min_re + (x / (double)WIDTH) * (fract->max_re - fract->min_re);
            iter = julia_iter(cr, ci, fract->c_re, fract->c_im);

                color = get_color(iter, fract); //nuevo sistema de color sin paletas

            *(int *)(fract->addr + (y * fract->line_length + x * (fract->bpp / 8))) = color;
            x++;
        }
        y++;
    }
}
