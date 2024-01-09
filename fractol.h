/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:29:04 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/09 17:00:58 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

# define WIDTH	1000
# define HEIGHT	1000

# define BLACK	0x00000000
# define WHITE	0x00FFFFFF
# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define IKB	0x00002FA7
# define PINK	0x00FD6C9E
# define PURPLE	0x00FF00FF
# define YELLOW	0x00FFFF00
# define CYAN	0x0000FFFF

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_complex
{
	double	real;
	double	i;
}				t_complex;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;
	char	*name;
	double	max_valid;
	int		definition;
	double	x_shift;
	double	y_shift;
	double	zoom;
	double	julia_real;
	double	julia_i;
	int		color_shift;
}				t_fractal;

void		fractal_init(t_fractal *fractal);

double		map_scale(double num, double n_min, double n_max, double old_max);
t_complex	complex_sum(t_complex z1, t_complex z2);
t_complex	complex_sqr(t_complex z);
double		atod(char *num);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		pixel_treatment(t_fractal *fractal, int x, int y);
void		fractal_render(t_fractal *fractal);

int			key_bind(int key, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_bind(int button, int x, int y, t_fractal *fractal);
int			pointer_tracking(int x, int y, t_fractal *fractal, int button);

int			ft_strncmp(const char *s1, const char *s2, size_t size);

int			ft_printf(const char *format, ...);
int			ft_print_format(char type, va_list params);
size_t		ft_strlen(const char *str);

int			ft_printchar(char c);
int			ft_printstr(char *s);
int			ft_printnbr(long n, char c);
int			ft_printpointer(unsigned long long n);
int			ft_printptr(unsigned long long n);

#endif