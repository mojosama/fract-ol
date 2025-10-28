/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:14:31 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/09 11:42:58 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	int		a;
	size_t	i;

	a = 0;
	i = 0;
	if (!s1)
	{
		if (!s2)
			return (0);
		else
			return (*s2);
	}
	else if (!s2)
		return (*s1);
	while (a == 0 && i < size && (s1[i] || s2[i]))
	{
		a = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (a);
}
