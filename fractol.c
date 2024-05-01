/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:52:23 by dmoroz            #+#    #+#             */
/*   Updated: 2024/05/01 21:29:58 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_state(t_state *state);

int	main(int ac, char **av)
{
	t_state	state;

	parse_params(ac, av, &state);
	init_state(&state);
	set_hooks(&state);
	draw(&state);
	mlx_loop(state.mlx_ptr);
}

void	init_state(t_state *state)
{
	state->mlx_ptr = mlx_init();
	state->win_ptr = mlx_new_window(state->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_NAME);
	state->img_ptr = mlx_new_image(state->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	state->img_data = (int *)mlx_get_data_addr(state->img_ptr,
			&state->bits_per_pixel, &state->size_line, &state->endian);
	if (state->bits_per_pixel != 32)
	{
		ft_putendl_fd("Unfair!", STDOUT_FILENO);
		exit(1);
	}
	state->zoom = 1.0;
	state->shift_x = 0;
	state->shift_y = 0;
	state->color = 0x00F100;
	state->iter_tresh = 1000;
}

void	clean_n_exit(t_state *s)
{
	mlx_destroy_image(s->mlx_ptr, s->img_ptr);
	mlx_destroy_window(s->mlx_ptr, s->win_ptr);
	exit(0);
}
