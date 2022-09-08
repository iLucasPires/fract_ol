#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
} t_mlx;

typedef struct s_var
{
	double min[2];
	double max[2];
	double center[2];
	int color[3];
	double complex[4];
	int max_interation;
	int (*fractal)(double *complex, int max_interation);
} t_var;

typedef struct s_data
{
	t_mlx mlx;
	t_var var;
} t_data;

#endif