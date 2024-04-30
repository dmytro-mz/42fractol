#include "fractol.h"
#include <stdio.h>

int expose_hook(void *param)
{
    printf("expose_hook\n");
}

int key_hook(int keycode, void *param)
{
    printf("key_hook - keycode: %d\n", keycode);
}

int mouse_hook(int button, int x, int y, void *param)
{
    printf("mouse_hook - button: %d, x: %d, y: %d\n", button, x, y);
}

int loop_hook(void *param)
{
    printf("loop_hook\n");
}

void set_hooks(t_state *state)
{
    mlx_key_hook(state->win_ptr, key_hook, state);
    mlx_mouse_hook(state->win_ptr, mouse_hook, state);
    mlx_expose_hook(state->win_ptr, expose_hook, state);
    mlx_loop_hook(state->win_ptr, loop_hook, state);
}
