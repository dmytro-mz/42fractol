#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
# include "constants.h"
# include "libft.h"
# include <math.h>
# include <unistd.h> // for STD FD

typedef struct s_complex{
	double x;
    double y;
}       t_complex;

// complex utils
t_complex   add(t_complex a, t_complex b);
t_complex   sqr(t_complex a);
double      mod(t_complex a);

typedef struct s_state{
	void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *img_data;
    int bits_per_pixel;
    int size_line;
    int endian;
    double zoom;
    int shift_x;
    int shift_y;
    void (*fract_func_ptr)(void *);
}       t_state;

// fractal types
void julia();
void mandelbrot();

void parse_params(int ac, char **av, t_state *state);
void set_hooks(t_state *state);

#endif