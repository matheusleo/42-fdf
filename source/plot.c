/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:51:52 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/12 19:09:49 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define EDGE 10

/*
it is assumed that the Xo from the original equation is always zero (0)
*/
int	calculate_x_screen(int x_real, int z_real)
{
	int	x_screen;

	x_screen = (x_real - z_real) * cos(0.46) * EDGE + WIN_WIDTH / 2;
	return (x_screen);
}

int	calculate_y_screen(int x_real, int z_real, int y_real)
{
	int	y_screen;

	y_screen = ((x_real + z_real) * sin(0.46) - y_real + 1) * EDGE + WIN_HEIGHT / 2;
	return (y_screen);
}

void	put_line(t_app *app, t_list *line_node)
{
	int			*line;
	int			*line_next;
	int			cur_col;
	static int	cur_row = 0;

	line = line_node->content;
	line_next = line_node->next->content;
	cur_col = 0;
	while (cur_col < app->fdf->cols)
	{
		if (cur_col < app->fdf->cols - 1 && (line[cur_col + 1] + 1))
			bresenham(app, calculate_x_screen(cur_col, cur_row), calculate_y_screen(cur_col, cur_row, line[cur_col]), \
			calculate_x_screen(cur_col + 1, cur_row), calculate_y_screen(cur_col + 1, cur_row, line[cur_col + 1]));
		if (line_next)
			bresenham(app, calculate_x_screen(cur_col, cur_row), calculate_y_screen(cur_col, cur_row, line[cur_col]), \
			calculate_x_screen(cur_col, cur_row + 1), calculate_y_screen(cur_col, cur_row + 1, line_next[cur_col]));
		cur_col++;
	}
	cur_row++;
}

void	put_map(t_app *app)
{
	t_list	*matrix_head;

	matrix_head = app->fdf->map_matrix;
	app->color = BLUE_CODE;
	lstiter(matrix_head, app, put_line);
}
