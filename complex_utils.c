#include "fractol.h"

t_complex add(t_complex a, t_complex b)
{
	t_complex c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex sqr(t_complex a)
{
	t_complex c;
	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

double mod(t_complex a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
