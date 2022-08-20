/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:14:29 by lpires-n          #+#    #+#             */
/*   Updated: 2022/08/20 19:42:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

# define WIDTH 1000 
# define HEIGHT 1000 
# define MAX_INTERACTION 100

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_fractal
{
	char	*name;
	int		i;
	int		x;
	int		y;
	int		result;
	int		color;
	double	cpx_x;
	double	cpx_y;
	double	cpx_ky;
	double	cpx_kx;
	double	z_im;
	double	z_real;
	double	aux_real;
	float 	min_r;
	float 	max_r;
	float 	min_im;
	float 	max_im;
}				t_fractal;

typedef struct    s_mano 
{
    int    x;
    int    y;
    double    xmax;
    double    xmin;
    double    ymax;
    double    ymin;
    double    z_real;
    double    z_img;
    double    c_real;
    double    c_img;
    double    max_iterations;
}                t_mano;


void set_fractal(t_fractal *data);


//fractal functions
int julia(t_fractal *data);
int mandelbrot(t_fractal *data);

//utils
double ft_pow(double number);
double find_c(float min, float max, float axle , int size);