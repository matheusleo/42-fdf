/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:57:06 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/12 11:59:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	bresenham_fast_x(t_app *app, int x_i, int y_i, int x_f, int y_f)
{
	int		d_x;
	int		d_y;
	int		inc_x;
	int		inc_y;
	double	eps;

	d_x = x_f - x_i;
	d_y = y_f - y_i;
	inc_x = ft_ternary(d_x > 0, 1, -1);
	inc_y = ft_ternary(d_y > 0, 1, -1);
	eps = 0;
	while (ft_ternary(inc_x < 0, x_i >= x_f, x_i <= x_f))
	{
		put_pixel(app, x_i + 250, y_i + 250, RED_CODE);
		eps += abs(d_y);
		if (eps >= abs(d_x))
		{
			y_i += inc_x;
			eps -= abs(d_x);
		}
		x_i += inc_x;
	}
}

static void	bresenham_fast_y(t_app *app, int x_i, int y_i, int x_f, int y_f)
{
	int		d_x;
	int		d_y;
	int		inc_x;
	int		inc_y;
	double	eps;

	d_x = x_f - x_i;
	d_y = y_f - y_i;
	inc_x = ft_ternary(d_x > 0, 1, -1);
	inc_y = ft_ternary(d_y > 0, 1, -1);
	eps = 0;
	while (ft_ternary(inc_y < 0, y_i >= y_f, y_i <= y_f))
	{
		put_pixel(app, x_i + 250, y_i + 250, MANGO_CODE);
		eps += abs(d_x);
		if (eps >= abs(d_y))
		{
			x_i += inc_x;
			eps -= abs(d_y);
		}
		y_i += inc_y;
	}
}

void	bresenham(t_app *app, int x_init, int y_init, int x_final, int y_final)
{
	int	d_x;
	int	d_y;

	d_x = x_final - x_init;
	d_y = y_final - y_init;
	if (abs(d_x) > abs(d_y))
		bresenham_fast_x(app, x_init, y_init, x_final, y_final);
	else
		bresenham_fast_y(app, x_init, y_init, x_final, y_final);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}
