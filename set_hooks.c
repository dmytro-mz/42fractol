/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:58:13 by dmoroz            #+#    #+#             */
/*   Updated: 2024/05/01 20:58:13 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
int	key_hook(int keycode, t_state *s)
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
		s->color *= COLOR_SHIFT;
	else if (keycode == 61)
		s->iter_tresh += 50;
	else if (keycode == 45)
		s->iter_tresh = 100;
	draw(s);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_state *s)
{
	if (button == 4)
	{
		s->zoom *= ZOOM_MULT;
		s->shift_x = s->shift_x * ZOOM_MULT + (x - WINDOW_WIDTH / 2) * 0.9;
		s->shift_y = s->shift_y * ZOOM_MULT + (y - WINDOW_HEIGHT / 2) * 0.9;
	}
	else if (button == 5)
	{
		s->zoom = s->zoom / ZOOM_MULT + 1e-5;
		s->shift_x = s->shift_x / ZOOM_MULT - (x - WINDOW_WIDTH / 2) * 0.9;
		s->shift_y = s->shift_y / ZOOM_MULT - (y - WINDOW_HEIGHT / 2) * 0.9;
	}
	draw(s);
	return (0);
}

int	put_image_hook(t_state *s)
{
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
	return (0);
}

int	exit_hook(t_state *s)
{
	clean_n_exit(s);
	return (0);
}

void	set_hooks(t_state *state)
{
	mlx_key_hook(state->win_ptr, key_hook, state);
	mlx_mouse_hook(state->win_ptr, mouse_hook, state);
	mlx_expose_hook(state->win_ptr, put_image_hook, state);
	mlx_hook(state->win_ptr, 17, 0, exit_hook, state);
}
