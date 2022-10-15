/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:38:21 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/15 16:14:41 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

// Map related struct
typedef struct s_fdf
{
	int		cols;
	int		rows;
	int		map_fd;
	int		edge_len;
	int		zoom;
	int		x_offset;
	int		y_offset;
	int		level_height;
	double	angle_x;
	double	angle_z;
	double	angle_y;
	t_list	*map_matrix;
}				t_fdf;

// MLX related struct
typedef struct s_app
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		img_bpp;
	int		img_line_size;
	int		img_endian;
	int		color;
	t_fdf	*fdf;
}				t_app;

// Bresenham related struct
typedef struct s_coord
{
	int	x;
	int	y;

}				t_coord;

typedef struct s_real
{
	int	x;
	int	z;
	int	y;
}				t_real;

// General macros
# define WIN_HEIGHT 720
# define WIN_WIDTH 1080

// Key code macros
# define ESC_CODE 65307
# define W_CODE 119
# define A_CODE 97
# define S_CODE 115
# define D_CODE 100
# define Q_CODE 113
# define E_CODE 101
# define GT_CODE 46
# define LT_CODE 44
# define PLUS_CODE 61
# define MINUS_CODE 45
# define UP_CODE 65362
# define LEFT_CODE 65361
# define DOWN_CODE 65364
# define RIGHT_CODE 65363

// Events code macros
# define ON_DESTROY 17

// Colors code macros
# define WHITE_CODE 1694498815
# define RED_CODE 16711680
# define GREEN_CODE 65280
# define MANGO_CODE 1693956097
# define VIOLET_CODE 1692097210

// Window && Image management functions
void	clean_win(t_app *app);
int		shutdown_app(t_app *app);
t_app	*init_app(t_fdf *fdf);

// User's input related functions
int		validate_user_input(int argc, char *argv[]);

// Map related functions
int		*parse_line(char *line);
t_list	*parse_map(t_fdf *fdf);

// Plot pixels related functions
void	put_map(t_app *app);
void	put_pixel(t_app *app, int x, int y, int color);
void	bresenham(t_app *app, t_coord *pos_i, t_coord *pos_f);

// Key handler functions
int		translate_map(int keycode, t_app *app);
int		rotate_map(int keycode, t_app *app);
t_real	rotate_x(t_app *app, int x_real, int z_real, int y_real);
t_real	rotate_y(t_app *app, int x_real, int z_real, int y_real);
t_real	rotate_z(t_app *app, int x_real, int z_real, int y_real);
int		zoom_map(int keycode, t_app *app);
int		color_handler(int keycode, t_app *app);
int		level_handler(int keycode, t_app *app);
int		key_handler(int keycode, t_app *app);

// Utils
void	lstiter(t_list *lst, t_app *app, void (*f)(t_app *, t_list *, int));
int		ternary(int codition, int return_true, int return_false);

#endif
