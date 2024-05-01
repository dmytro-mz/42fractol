/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:45:36 by dmoroz            #+#    #+#             */
/*   Updated: 2024/05/01 20:45:36 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_add(t_complex a, t_complex b)
{
	t_complex	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

t_complex	c_sqr(t_complex a)
{
	t_complex	res;

	res.x = a.x * a.x - a.y * a.y;
	res.y = 2 * a.x * a.y;
	return (res);
}

double	c_mod(t_complex a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}
