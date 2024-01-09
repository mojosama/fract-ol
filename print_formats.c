/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:37:30 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/09 16:53:01 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_printpointer(unsigned long long n)
{
	if (!n)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (2 + ft_printptr(n));
}

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_printnbr(long n, char c)
{
	char	*base;
	int		count;
	size_t	base_size;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	base_size = ft_strlen(base);
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (ft_printnbr(-n, c) + 1);
	}
	else if (n < (long)base_size)
		return (write(1, base + n, 1));
	else
	{
		count = ft_printnbr(n / base_size, c);
		return (count + write(1, base + (n % base_size), 1));
	}
}

int	ft_printptr(unsigned long long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	if (n < 16)
		return (write(1, base + n, 1));
	else
	{
		count = ft_printptr(n / 16);
		if (count == -1)
			return (-1);
		return (count + write(1, base + (n % 16), 1));
	}
}
