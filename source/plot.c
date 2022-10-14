/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:51:52 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/13 22:48:34 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	calculate_x_screen(int x_real, int z_real, t_app *app)
{
	t_fdf	*fdf;
	int		x_screen;
	int		edge;

	fdf = app->fdf;
	edge = fdf->edge_len * fdf->zoom;
	x_screen = (x_real - z_real) * cos(0.46) * edge;
	return (x_screen + (WIN_WIDTH / 2 + fdf->x_offset));
}

static int	calculate_y_screen(int x_real, int z_real, int y_real, t_app *app)
{
	t_fdf	*fdf;
	int		y_screen;
	int		edge;
	int		level;

	fdf = app->fdf;
	edge = fdf->edge_len * fdf->zoom;
	level = y_real * fdf->level_height * fdf->zoom;
	y_screen = ((x_real + z_real) * sin(0.46) - y_real + 1) * edge - level;
	return (y_screen + (WIN_HEIGHT / 2 + fdf->y_offset));
}

static t_coord	calc_coord(t_app *app, int x_real, int z_real, int y_real)
{
	t_coord	coord;

	coord.x = calculate_x_screen(x_real, z_real, app);
	coord.y = calculate_y_screen(x_real, z_real, y_real, app);
	return (coord);
}

static void	put_line(t_app *app, t_list *line_node, int cur_row)
{
	int			*line;
	int			*line_next;
	int			cur_col;
	t_coord		coord_i;
	t_coord		coord_f;

	line = line_node->content;
	line_next = line_node->next->content;
	cur_col = 0;
	while (cur_col < app->fdf->cols)
	{
		if (cur_col < app->fdf->cols - 1 && (line[cur_col + 1] + 1))
		{
			coord_i = calc_coord(app, cur_col, cur_row, line[cur_col]);
			coord_f = calc_coord(app, cur_col + 1, cur_row, line[cur_col + 1]);
			bresenham(app, &coord_i, &coord_f);
		}
		if (line_next)
		{
			coord_i = calc_coord(app, cur_col, cur_row, line[cur_col]);
			coord_f = calc_coord(app, cur_col, cur_row + 1, line_next[cur_col]);
			bresenham(app, &coord_i, &coord_f);
		}
		cur_col++;
	}
}

void	put_map(t_app *app)
{
	t_list	*matrix_head;

	clean_win(app);
	matrix_head = app->fdf->map_matrix;
	lstiter(matrix_head, app, put_line);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}
