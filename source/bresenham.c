/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:57:06 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/10 13:06:59 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
	Bresenham's is an algorithim developed by the computer scientist
	Jack Elton Bresenham to put lines into a raster by deciding
	which pixel should be the next one based on the distance between the
	current pixel (xi, yi) from the possible next - that can be (xi + 1, yi)
	or (xi + 1, yi + 1)
*/
void	bresenham(t_app *app, int x_init, int y_init, int x_final, int y_final)
{
	int		d_x;
	int		d_y;
	int		abs_d_x;
	int		abs_d_y;
	int		inc_x;
	int		inc_y;
	double	eps;

	d_x = x_final - x_init;
	d_y = y_final - y_init;
	abs_d_x = abs(d_x);
	abs_d_y = abs(d_y);
	inc_x = d_x > 0 ? 1 : -1;
	inc_y = d_y > 0 ? 1 : -1;
	eps = 0;
	if (abs_d_x > abs_d_y)
	{
		for (int x = x_init, y = y_init; inc_x < 0 ? x >= x_final : x <= x_final; x += inc_x)
		{
			put_pixel(app, x + 250, y + 250, RED_CODE);
			eps += abs_d_y;
			if (eps >= abs_d_x)
			{
				y += inc_y;
				eps -= abs_d_x;
			}
		}
	}
	else
	{
		for (int x = x_init, y = y_init; inc_y < 0 ? y >= y_final : y <= y_final; y += inc_y)
		{
			put_pixel(app, x + 250, y + 250, GREEN_CODE);
			eps += abs_d_x;
			if (eps >= abs_d_y)
			{
				x += inc_x;
				eps -= abs_d_y;
			}
		}
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}
