/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:19:25 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/15 15:51:44 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	define_color(int key, t_fractal *fractal)
{
	if (key == 48)
		fractal->base_color = BLACK;
	else if (key == 49)
		fractal->base_color = MBLUE;
	else if (key == 50)
		fractal->base_color = IKB;
	else if (key == 51)
		fractal->base_color = ORANGE;
	else if (key == 52)
		fractal->base_color = GREEN;
	else if (key == 53)
		fractal->base_color = YELLOW;
	else if (key == 54)
		fractal->base_color = RED;
	else if (key == 55)
		fractal->base_color = PURPLE;
	else if (key == 56)
		fractal->base_color = PINK;
	else if (key == 57)
		fractal->base_color = ORANGE;
}

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
	else if (key >= 48 && key <= 57)
		define_color(key, fractal);
	else if (key == 106)
		fractal->name = "Julia";
	else if (key == 109)
		fractal->name = "Mandelbrot";
	else if (key == 98)
		fractal->name = "Burning ship";
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
	if (*(frac->name) == 'j' || *(frac->name) == 'J')
	{
		frac->julia_real = map_scale(x, -1, 1, WIDTH) * frac->zoom;
		frac->julia_real += frac->x_shift;
		frac->julia_i = map_scale(y, -1, 1, HEIGHT) * frac->zoom;
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
