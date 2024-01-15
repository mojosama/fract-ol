/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:22:10 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/15 14:35:50 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_error(void)
{
	ft_printf("\n Incorrect parameters. Please enter valid ones.\n\n");
	ft_printf(" Here is a list of the possibilities:\n");
	ft_printf(" - Mandelbrot\n");
	ft_printf(" - Julia <real part> <imaginary part>\n");
	ft_printf(" - Burning ship\n\n");
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10)
				|| !ft_strncmp(av[1], "Mandelbrot", 10)
				|| !ft_strncmp(av[1], "burning ship", 12)
				|| !ft_strncmp(av[1], "Burning ship", 12)))
		|| (ac == 4 && (!ft_strncmp(av[1], "julia", 5)
				|| !ft_strncmp(av[1], "Julia", 5))))
	{
		fractal.name = av[1];
		if (ac == 4)
		{
			fractal.julia_real = atod(av[2]);
			fractal.julia_i = atod(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
	{
		print_error();
		exit(EXIT_FAILURE);
	}
	return (0);
}
