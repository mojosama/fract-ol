/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:45:53 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/09 18:49:53 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	fractal_type(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5)
		|| !ft_strncmp(fractal->name, "Julia", 5))
	{
		c->real = fractal->julia_real;
		c->i = fractal->julia_i;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
	}
}

void	pixel_treatment(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = map_scale(x, -2, 2, WIDTH) * fractal->zoom + fractal->x_shift;
	z.i = map_scale(y, -2, 2, HEIGHT) * fractal->zoom + fractal->y_shift;
	fractal_type(&z, &c, fractal);
	while (i < fractal->definition)
	{
		z = complex_sum(complex_sqr(z), c);
		if ((z.real * z.real) + (z.i * z.i) >= fractal->max_valid)
		{
			color = map_scale(i, IKB, PURPLE,
					fractal->definition) + 10000 * fractal->color_shift;
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, IKB);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			pixel_treatment(fractal, x++, y);
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win,
		fractal->img.img, 0, 0);
}
