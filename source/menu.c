/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:43:06 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/16 16:42:04 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	put_string(t_app *app, char *string, int index)
{
	int	y_offset;

	y_offset = 75 + 25 * index;
	mlx_string_put(app->mlx, app->win, 50, y_offset, GREEN_CODE, string);
	y_offset += 25;
}

int	put_menu(t_app *app)
{
	static char	*menu[207] = {
		"Translate map: UP, DOWN, LEFT, RIGHT",
		"Rotate map:",
		"  X-axis: W, S",
		"  Y-axis: A, D",
		"  Z-axis: Q, E",
		"Zoom in/out: +/-",
		"Change colors: 1, 2",
		"Increment/Decrement level: <, >",
		"Projection:",
		"  isometric: I",
		"  paralel: P",
		"RESET: R"
	};
	int			counter;
	char		*header;

	header = "        FDF MENU - mleonard";
	counter = -1;
	mlx_string_put(app->mlx, app->win, 50, 50, MANGO_CODE, header);
	while (menu[++counter])
		put_string(app, menu[counter], counter);
	return (1);
}
