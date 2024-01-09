/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:53:30 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/09 16:55:42 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		count;
	int		new_c;

	va_start(params, format);
	count = 0;
	if (!format || write(1, 0, 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format != '%')
			count += write(1, format++, 1);
		else
		{
			format++;
			new_c = ft_print_format(*format, params);
			if (new_c >= 0)
				count += new_c;
			else
				return (-1);
			format++;
		}
	}
	va_end(params);
	return (count);
}

int	ft_print_format(char type, va_list params)
{
	if (type == 'c')
		return (ft_printchar((char)va_arg(params, int)));
	else if (type == 's')
		return (ft_printstr((char *)va_arg(params, char *)));
	else if (type == 'p')
		return (ft_printpointer(va_arg(params, unsigned long long)));
	else if (type == 'i' || type == 'd')
		return (ft_printnbr((long)va_arg(params, int), type));
	else if (type == 'u')
		return (ft_printnbr((long)va_arg(params, unsigned int), type));
	else if (type == 'x' || type == 'X')
		return (ft_printnbr((long)va_arg(params, unsigned int), type));
	else if (type == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	if (!str)
		return (0);
	while (str[l])
		l++;
	return (l);
}
