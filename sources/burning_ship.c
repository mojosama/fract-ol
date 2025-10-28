/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:11:10 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/15 15:30:58 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	burning_ship_render(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = map_scale(x, -2, 2, WIDTH) * fractal->zoom + fractal->x_shift;
	z.i = map_scale(y, -2, 2, HEIGHT) * fractal->zoom + fractal->y_shift;
	c.real = z.real;
	c.i = z.i;
	while (i < fractal->definition)
	{
		z.real = ft_abs(z.real);
		z.i = ft_abs(z.i);
		z = complex_sum(complex_sqr(z), c);
		if ((z.real * z.real) + (z.i * z.i) >= fractal->max_valid)
		{
			color = map_scale(i, fractal->base_color, WHITE,
					fractal->definition) + 10000 * fractal->color_shift;
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, fractal->base_color);
}

void	burning_ship(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			burning_ship_render(fractal, x++, y);
		y++;
	}
}
