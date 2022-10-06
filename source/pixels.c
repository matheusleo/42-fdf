/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:43:42 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/05 23:58:59 by mleonard         ###   ########.fr       */
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
	int	d_x;
	int	d_y;
	int	p;

	d_x = x_final - x_init;
	d_y = y_final - y_init;
	p = 2 * d_y - d_x;
	while (x_init <= x_final)
	{
		put_pixel(app, x_init, y_init, RED_CODE);
		x_init++;
		if (p < 0)
			p += 2 * (d_y);
		else if (p >= 0)
		{
			p += 2 * (d_y - d_x);
			y_init++;
		}
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}

void	put_pixel(t_app *app, int x, int y, int color)
{
	int		offset;
	char	*real_pixel;

	offset = y * app->img_line_size + x * (app->img_bpp / 8);
	real_pixel = app->img_addr + offset;
	*(unsigned int *)real_pixel = color;
}
