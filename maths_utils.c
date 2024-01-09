/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:41:59 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/09 16:43:33 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_scale(double num, double new_min, double new_max, double old_max)
{
	return (((new_max - new_min) * num / old_max) + new_min);
}

t_complex	complex_sum(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = z1.real + z2.real;
	res.i = z1.i + z2.i;
	return (res);
}

t_complex	complex_sqr(t_complex z)
{
	t_complex	res;

	res.real = (z.real * z.real) - (z.i * z.i);
	res.i = 2 * z.real * z.i;
	return (res);
}

double	atod(char *num)
{
	double	res;
	double	i;
	int		sign;

	res = 0.0;
	i = 1;
	sign = 1;
	if (!num)
		return (0);
	while (*num <= ' ')
		num++;
	while (*num == '-' || *num == '+')
		if (*num++ == '-')
			sign *= -1;
	while (*num != '.' && *num && *num >= '0' && *num <= '9')
		res = (res * 10) + (*num++ - '0');
	if (*num == '.')
		num++;
	while (*num && *num >= '0' && *num <= '9')
	{
		i /= 10;
		res += (*num++ - '0') * i;
	}
	return (sign * res);
}
