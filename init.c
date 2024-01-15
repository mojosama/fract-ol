/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:19:56 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/11 11:05:45 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->max_valid = 4;
	fractal->definition = 30;
	fractal->x_shift = 0.0;
	fractal->y_shift = 0.0;
	fractal->zoom = 1.0;
	fractal->color_shift = 0;
	fractal->base_color = BLACK;
}

static void	events_init(t_fractal *fract)
{
	mlx_hook(fract->mlx_win, KeyPress, KeyPressMask, key_bind, fract);
	mlx_hook(fract->mlx_win, ButtonPress, ButtonPressMask, mouse_bind, fract);
	mlx_hook(fract->mlx_win, 17, StructureNotifyMask, close_handler, fract);
}

void	fractal_init(t_fractal *fract)
{
	fract->mlx_ptr = mlx_init();
	if (!fract->mlx_ptr)
		exit(EXIT_FAILURE);
	fract->mlx_win = mlx_new_window(fract->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	if (!fract->mlx_win)
	{
		mlx_destroy_display(fract->mlx_ptr);
		free(fract->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	fract->img.img = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
	if (!fract->img.img)
	{
		mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
		mlx_destroy_display(fract->mlx_ptr);
		free(fract->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	fract->img.addr = mlx_get_data_addr(fract->img.img,
			&fract->img.bits_per_pixel,
			&fract->img.line_length, &fract->img.endian);
	events_init(fract);
	data_init(fract);
}
