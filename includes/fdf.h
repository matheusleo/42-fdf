/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:38:21 by mleonard          #+#    #+#             */
/*   Updated: 2022/09/30 09:33:13 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

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
}				t_app;

// Map related struct
typedef struct s_fdf
{
	int		cols;
	int		rows;
	int		map_fd;
	t_list	*map_matrix;
}				t_fdf;

// General macros
# define WIN_HEIGHT 540
# define WIN_WIDTH 960

// Key code macros
# define ESC_CODE 65307
# define W_CODE 119
# define A_CODE 97
# define S_CODE 115
# define D_CODE 100
# define PLUS_CODE 61
# define MINUS_CODE 45
# define UP_CODE 65362
# define LEFT_CODE 65361
# define DOWN_CODE 65364
# define RIGHT_CODE 65363

// Events code macros
# define ON_DESTROY 17

// Window management functions
void	init_app(void);

// User's input related functions
int		validate_user_input(int argc, char *argv[]);

// Map related functions
int		*parse_line(int map_fd);
t_list	*parse_map(int map_fd);

#endif
