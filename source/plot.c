/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:51:52 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/12 22:54:19 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define EDGE 10

/*
it is assumed that the Xo from the original equation is always zero (0)
*/
int	calculate_x_screen(int x_real, int z_real, t_app *app)
{
	t_fdf	*fdf;
	int		x_screen;
	int		edge;

	fdf = app->fdf;
	edge = fdf->edge_len * fdf->zoom;
	x_screen = (x_real - z_real) * cos(0.46) * edge;
	return (x_screen + (WIN_WIDTH / 2 + fdf->x_offset));
}

int	calculate_y_screen(int x_real, int z_real, int y_real, t_app *app)
{
	t_fdf	*fdf;
	int		y_screen;
	int		edge;

	fdf = app->fdf;
	edge = fdf->edge_len * fdf->zoom;
	y_screen = ((x_real + z_real) * sin(0.46) - y_real + 1) * edge;
	return (y_screen + (WIN_HEIGHT / 2 + fdf->y_offset));
}

void	put_line(t_app *app, t_list *line_node, int cur_row)
{
	int			*line;
	int			*line_next;
	int			cur_col;

	line = line_node->content;
	line_next = line_node->next->content;
	cur_col = 0;
	while (cur_col < app->fdf->cols)
	{
		if (cur_col < app->fdf->cols - 1 && (line[cur_col + 1] + 1))
			bresenham(app, calculate_x_screen(cur_col, cur_row, app), calculate_y_screen(cur_col, cur_row, line[cur_col], app), \
			calculate_x_screen(cur_col + 1, cur_row, app), calculate_y_screen(cur_col + 1, cur_row, line[cur_col + 1], app));
		if (line_next)
			bresenham(app, calculate_x_screen(cur_col, cur_row, app), calculate_y_screen(cur_col, cur_row, line[cur_col], app), \
			calculate_x_screen(cur_col, cur_row + 1, app), calculate_y_screen(cur_col, cur_row + 1, line_next[cur_col], app));
		cur_col++;
	}
}

void	put_map(t_app *app)
{
	t_list	*matrix_head;

	clean_win(app);
	matrix_head = app->fdf->map_matrix;
	lstiter(matrix_head, app, put_line);
}
