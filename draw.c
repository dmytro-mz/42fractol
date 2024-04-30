#include "fractol.h"

double pixel_to_coordinate(int xy, double shift, int max, double zoom);

void draw(t_state *s)
{
    int x;
    int y;
    int i;
    t_complex z;

    x = 0;
    while(x < WINDOW_WIDTH)
    {
        y = 0;
        while (y < WINDOW_HEIGHT)
        {
            z.x = pixel_to_coordinate(x, s->shift_x, WINDOW_HEIGHT, s->zoom);
            z.y = pixel_to_coordinate(y, s->shift_y, WINDOW_HEIGHT, s->zoom);
            i = 0;
            while (mod(z) < ESCAPE_RADIUS && i < s->iter_tresh)
            {
                z = add(sqr(z), s->c);
                i+=2;
            }
            s->img_data[y * s->size_line / 4 + x] = i * s->color;
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
}

double pixel_to_coordinate(int xy, double shift, int max, double zoom)
{
    return ((2.0 * (xy + shift) / max - 1.0) * ESCAPE_RADIUS / zoom);
}
