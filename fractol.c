#include "fractol.h"

void init_state(t_state *state);

int main(int ac, char **av)
{
    t_state state;

    parse_params(ac, av, &state); // TODO finish
    init_state(&state);
    set_hooks(&state);
    // draw_initial();
    mlx_put_image_to_window(state.mlx_ptr, state.win_ptr, state.img_ptr, 0, 0);
    mlx_loop(state.mlx_ptr);
}

void init_state(t_state *state)
{
    state->mlx_ptr = mlx_init();
    state->win_ptr = mlx_new_window(state->mlx_ptr, SCREEN_WIDTH, 
        SCREEN_HEIGHT, WINDOW_NAME);
    state->img_ptr = mlx_new_image(state->mlx_ptr, SCREEN_WIDTH, 
        SCREEN_HEIGHT);
    state->img_data = mlx_get_data_addr(state->img_ptr, &state->bits_per_pixel,
        &state->size_line, &state->endian);
    state->zoom = 0.0;
    state->shift_x = 0;
    state->shift_y = 0;
}
