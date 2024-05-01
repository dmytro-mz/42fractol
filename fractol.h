/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:55:01 by dmoroz            #+#    #+#             */
/*   Updated: 2024/05/01 20:55:01 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "constants.h"
# include "libft.h"
# include <math.h>
# include <unistd.h> // for STD FD

typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;

// complex utils
t_complex	c_add(t_complex a, t_complex b);
t_complex	c_sqr(t_complex a);
double		c_mod(t_complex a);

typedef struct s_state
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_complex	c;
	double		zoom;
	double		shift_x;
	double		shift_y;
	int			color;
	int			iter_tresh;
	int			(*fract_func_ptr)(int, int, struct s_state *);
}		t_state;

// fractal types
int			julia(int x, int y, t_state *s);
int			mandelbrot(int x, int y, t_state *s);
int			burning_ship(int x, int y, t_state *s);

void		parse_params(int ac, char **av, t_state *state);
void		set_hooks(t_state *state);
void		draw(t_state *s);
void		show_help(void);
void		clean_n_exit(t_state *s);

#endif