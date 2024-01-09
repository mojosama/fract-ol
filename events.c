/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:19:25 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/09 18:29:25 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_bind(int key, t_fractal *fractal)
{
	if (key == 65307 || key == 113)
		close_handler(fractal);
	else if (key == 65361 || key == 97)
		fractal->x_shift -= 0.1 * fractal->zoom;
	else if (key == 65363 || key == 100)
		fractal->x_shift += 0.1 * fractal->zoom;
	else if (key == 65362 || key == 119)
		fractal->y_shift -= 0.1 * fractal->zoom;
	else if (key == 65364 || key == 115)
		fractal->y_shift += 0.1 * fractal->zoom;
	else if (key == 65451)
		fractal->definition += 10;
	else if (key == 65453)
		fractal->definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img);
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	mouse_bind(int button, int x, int y, t_fractal *fractal)
{
	if (button == 1)
		pointer_tracking(x, y, fractal, button);
	else if (button == 3)
		pointer_tracking(x, y, fractal, button);
	else if (button == 4)
	{
		fractal->zoom *= 0.8;
		fractal->x_shift += ((x - (WIDTH / 2.0)) / WIDTH) * fractal->zoom;
		fractal->y_shift += ((y - (HEIGHT / 2.0)) / HEIGHT) * fractal->zoom;
	}
	else if (button == 5)
	{
		fractal->zoom *= 1.2;
		fractal->x_shift -= ((x - (WIDTH / 2.0)) / WIDTH) * fractal->zoom;
		fractal->y_shift -= ((y - (HEIGHT / 2.0)) / HEIGHT) * fractal->zoom;
	}
	fractal_render(fractal);
	return (0);
}

int	pointer_tracking(int x, int y, t_fractal *frac, int button)
{
	if (!ft_strncmp(frac->name, "julia", 5)
		|| !ft_strncmp(frac->name, "Julia", 5))
	{
		frac->julia_real = map_scale(x, -2, 2, WIDTH) * frac->zoom;
		frac->julia_real += frac->x_shift;
		frac->julia_i = map_scale(y, -2, 2, HEIGHT) * frac->zoom;
		frac->julia_i += frac->y_shift;
		fractal_render(frac);
	}
	else
	{
		if (button == 1)
			frac->color_shift++;
		else if (button == 3)
			frac->color_shift--;
	}
	return (0);
}
