#include "fractol.h"
#include <stdio.h>
void clean_n_exit(t_state *s);
/*
plus - 61
minus - 45
space - 32
esc - 65307
arrow left - 65361
arrow up - 65362
arrow right - 65363
arrow down - 65364
*/
int key_hook(int keycode, t_state *s)
{
    if (keycode == 65307)
        clean_n_exit(s);
    else if (keycode == 65361)
        s->shift_x -= SHIFT_SIZE;
    else if (keycode == 65363)
        s->shift_x += SHIFT_SIZE;
    else if (keycode == 65362)
        s->shift_y -= SHIFT_SIZE;
    else if (keycode == 65364)
        s->shift_y += SHIFT_SIZE;
    else if (keycode == 32)
        s->color *= 1.3;
    else if (keycode == 61)
        s->iter_tresh += 50;
    else if (keycode == 45)
        s->iter_tresh = 100;
    draw(s);
    printf("key_hook - keycode: %d\n", keycode);
    return (0);
}
int mouse_hook(int button, int x, int y, t_state *s)
{
    if (button == 4)
    {
        s->zoom *= 1.5;
        s->shift_x = s->shift_x * 1.5 + (x - WINDOW_WIDTH / 2) * 0.9;
        s->shift_y = s->shift_y * 1.5 + (y - WINDOW_HEIGHT / 2) * 0.9;
        // s->shift_y *= 1.5;
    }
    else if (button == 5)
    {
        s->zoom = s->zoom / 1.5 + 1e-5;
        // s->shift_x /= 1.5;
        // s->shift_y /= 1.5;
        s->shift_x = s->shift_x / 1.5 - (x - WINDOW_WIDTH / 2) * 0.9;
        s->shift_y = s->shift_y / 1.5 - (y - WINDOW_HEIGHT / 2) * 0.9;
    }
    draw(s);
    printf("mouse_hook - zoom: %f, x: %d, y: %d\n", s->zoom, x, y);
    return (0);
}

int put_image_hook(t_state *s)
{
    mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
    printf("put_image_hook\n");
    return (0);
}

// int mega_hook(void *p)
// {
//     printf("mega_hook\n");
// }
// # include <X11/Xlib.h>
// # include <X11/Xutil.h>
void set_hooks(t_state *state)
{
    mlx_key_hook(state->win_ptr, key_hook, state);
    mlx_mouse_hook(state->win_ptr, mouse_hook, state);
    mlx_expose_hook(state->win_ptr, put_image_hook, state);
    // mlx_loop_hook(state->win_ptr, put_image_hook, state);
    // mlx_hook(state->win_ptr, MotionNotify, 0, mega_hook, state);
}

void clean_n_exit(t_state *s)
{
    mlx_destroy_image(s->mlx_ptr, s->img_ptr);
    mlx_destroy_window(s->mlx_ptr, s->win_ptr);
    exit(0);
}
