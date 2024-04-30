#include "fractol.h"

void show_help(void);

void parse_params(int ac, char **av, t_state *state) // TODO parse complex number
{
    if (ac < 2)
        show_help();
    if (!ft_memcmp(av[1], "julia", 6)
        || !ft_memcmp(av[1], "Julia", 6)
        || !ft_memcmp(av[1], "1", 2))
        state->fract_func_ptr = julia;
    else if (!ft_memcmp(av[1], "mandelbrot", 11)
        || !ft_memcmp(av[1], "Mandelbrot", 11)
        || !ft_memcmp(av[1], "2", 2))
        state->fract_func_ptr = mandelbrot;
    else
        show_help();
    state->c.x = -0.5251993; // TODO read from av
    state->c.y = -0.5251993; // TODO read from av
}

void show_help(void)
{
    ft_putendl_fd("Usage:", STDOUT_FILENO);
    ft_putendl_fd("fractol <fractal type> "
        "[<real value> <imaginary value>]", STDOUT_FILENO);
    ft_putendl_fd("", STDOUT_FILENO);
    ft_putendl_fd("Example:", STDOUT_FILENO);
    ft_putendl_fd("fractol julia 0.1 -0.32", STDOUT_FILENO);
    ft_putendl_fd("fractol Mandelbrot", STDOUT_FILENO);
    ft_putendl_fd("", STDOUT_FILENO);
    ft_putendl_fd("Fractal types:", STDOUT_FILENO);
    ft_putendl_fd("  Julia - \"Julia\"/\"julia\"/\"1\"", STDOUT_FILENO);
    ft_putendl_fd("  Mandelbrot - \"Mandelbrot\"/"
        "\"mandelbrot\"/\"2\"", STDOUT_FILENO);
    ft_putendl_fd("", STDOUT_FILENO);
    ft_putendl_fd("Julia fractal type needs parameter which is a "
        "complex number", STDOUT_FILENO);
    ft_putendl_fd("Please provide real and imaginary parts as "
        "floating point numbers", STDOUT_FILENO);
    exit(1);
}
